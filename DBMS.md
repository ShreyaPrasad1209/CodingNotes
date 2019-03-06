# Database Management System

Data: Raw and isolated facts about an entity(recorded) eg - text, audio, video, image, etc<br>
Information: Processed, meaningful, usable data is Information<br>
Database: Collection of simmilar data.

Database Management System is a collection of interrelated data representing information relevant to an enterprise and a set of programs to store and retrieve those data in the most efficient and convinient manner and the collection of data is usually reffered as a database<br>
Where is database needed? How was data stored before computers

Disadvantage Of File System:
1) Data Redundancy
2) Data Inconsistency
3) Difficulty in accessing data
4) Data isolation
5) Security problem
6) Atomicity problem
7) Concurrent access anomalies
8) Integrity problem

In a database it can happen tha 90% of data is historic 10% is new which is used daily. So we seperately store them in order to reduce space ultimately reducing the memory access time. OLAP (Online Analytical Processing) - Historic, OLTP (Online Transaction Processing)

## Data Models:
1) **Relational Model:** Data is stored in tables called relational. Attributes (Columns) Tuple (Rows). Degree = no. of attributes. Cardinality = no. of tuples. Advantages: Simplicity, Structural Independance (only concerned about data and not with structure), Easy to use, Query capability, Scalable. Disadvantages: Structured limit (field length limit, type, etc), Cost (of softwares and implementing).
2) **ER (Entity Relationship) Model:** It defines the conceptual view of a database. It works around real world entities and the assosiation among them. At view level it is considered a good option for designing database. An entity is a person or a thing which has logical or physical existence in the real world. For example, in a school database, students, teachers, classes, and courses. An entity set is a collection of similar types of entities. Entities are represented by means of their properties, called attributes. For example, a student entity may have name, class, and age as attributes. Advantages: Better understanding (graphical), Easy conversion to other models, easy and straightforward. Disadvantages: Popular for high-level design, No industry standard for notation.
3) **Object Oriented Model:** This data model is another method of representing real world objects. It considers each object in the world as objects and isolates it from each other. It groups its related functionalities together and allows inheriting its functionality to other related sub-groups. Advantages: Codes are reused because of inheritance, More flexible to change, More organized. Disadvantage: Complex to implement, Not widely used.
> Both ER & Object Oriented Model are Object based model since they use real world objects
4) **Semi-Structured Model:** The data is modelled as a tree or rooted graph where the nodes and edges are labelled with names and/or have attributes associated with them. The data can exist without there being a schema, although it is possible that there is one. (XML, JSON) Advantages - It can represent the information of some data sources that cannot be constrained by schema, Data transfer is portable, flexible, schema can be easily changed, useful for browsers. Disadvantages - Queries are less efficient then in strucuted models.
5) **Hierarchial Model:** In hierarchical model, data is organized into a tree like structure with each record is having one parent record and many children. The main drawback of this model is that, it can have only one to many relationships between nodes. Rarely used.
6) **Network Model:** The network model was created to represent complex data relationships more effectively than the hierarchical model, to improve database performance. Advantages - Conceptual simplicity, handles more relationship type, data access flexibility, promotes data integrity. Disadvantages - system complexity, lack of structural dependencies.

> A database schema is the skeleton structure that represents the logical view of the entire database. It defines how the data is organized and how the relations among them are associated.

> Database users - Naive user, application programmer, sophisticated users, specialised users

> Database administrator - schema defination, access control, routine maintainance, storage structure and access method defination

## Keys:
1) **Superkey:** A combination of one or more attributes that uniquely defines a tuple in a relation are called superkey.
2) **Key:** Any combination of one or more attributes that uniquely defines a tuple in a relation and there is no proper subset of that combination of attributes that will uniquely define a tuple in a relation. Then this combination of attribute is called a key.<br>
![](res/Screenshot&#32;from&#32;2019-03-04&#32;16-45-17.png)
3) **Candidate Keys:** For any relational scheme if more then one key exist then each key is called a candidate key.
4) **Primary Key:** It is a candidate key that is chosen during the time of designing schema of the table.
5) **Secondary Key:** All candidate keys which are not primary key are secondary key.
6) **Foreign Key:** Foreign key is an attribute or a combination of attributes that refrences the primary key of some other relation.
7) **Composite Key:** Any key which is a combination of 2 or more attributes.

https://youtu.be/x_inLVXPlSU?list=PLmXKhU9FNesR1rSES7oLdJaNFgmuj0SYV

## Database Languages
1) DDL (Data Defination Language)
    - Define schema
    - Define integrity constraints (PRIMARY KEY, FOREIGN KEY, UNIQUE, NOT NULL, CHECK)
2) DML (Data Manipulation Language)
    - Retrive data
    - Insert data
    - Update data
    - Delete data
3) Query language (Data retrieval)
    - Relational Algebra (Procedural)
    - SQL (Declarative or Non Procedural)

## SQL (Structured Query Language)
It offers - DDL, DML, Integrity, View defination, Transaction control, Embedded SQL & Dynamic SQL, Authorization.<br>
Basic data type - char(n), varchar(n), int, small int, numeric(p, d), float(n), date, time, timestamp

Key functions of DBA:
- Schema defination
- Storage structure and access method defination
- Schema and physical organization modification
- Granting of authority for data access
- Routine maintainance (periodically backups, ensuring enough free space, monitoring jobs running and ensuring performance)

```SQL
CREATE TABLE STUDENT
(
    Roll_no varchar(12),
    Name char(50),
    Contact_no int,
    email_id varchar(12),
    PRIMARY KEY (Roll_no),
    FOREIGN KEY (Name) refrences (REC.Name)
);

INSERT INTO STUDENT values(...);
DELETE table_name;
DROP table_name;
ALTER TABLE table_name add (last_name VARCHAR(50), ...);
ALTER TABLE table_name DROP COLUMN last_name;
```

> Constraints - Keys (primary, foreign), Unique, Not Null

## Relational Algebra
1) Selection (σ)<br>
σ<sub>address = "Rohini"</sub> (table_name)
2) Projection (π)<br>
π<sub>name, address</sub> (student)
3) Rename (ρ)<br>
ρ<sub>s</sub>(student)
4) Cartesian Product (x)<br>
student x student_course_grade
5) Joins (student ⋈ student_course_grade)
   - Theta join(⋈θ): Say two tables mobile & laptop wit prices. purchase both but laptop price should be more than mobile then Mobile ⋈<sub>mobile.price < laptop.price</sub> Laptop
   - Equi join(⋈e): Equi join is a theta join with equal condition
   - Natural join(⋈): It's equi join without having equal column twice. Optimized way.
6) Outer Joins - Left Outer Join, Right Outer Join, Full Outer Join (Simply append other part with matching values rest set NULL, Full outer join includes elements from both table)<br>
![](res/Screenshot&#32;from&#32;2019-03-04&#32;18-36-35.png)
7) Aggregate functions - SUM(), COUNT(), AVG(), MIN(), MAX()<br>
G<sub>sum (Marks)</sub>(student_course_grade)
8) Generalisation - Only aggregate (above), Only grouping <sub>cid</sub>G (table), both <sub>cid</sub>G<sub>sum (Marks)</sub> (table) This last one will show a table with grouped values for distinct cid with corresponding summed up marks in each groups
9) Division: Result contains all tuples appear in R1(z) in combination with every tuple from R2(y) where Z = (x U y). Result will contain R1-R2 attributes. Best suited to queries that include 'for all'<br>
![](res/Screenshot&#32;from&#32;2019-03-04&#32;21-10-31.png)
10)  Set Union (Applies on relation) R1 U R2
11)  Set Intersection (Applies on relation) R1 ∩ R2
12)  Set Difference (Applies on relation) R1 - R2

![](res/Screenshot&#32;from&#32;2019-03-04&#32;21-51-28.png)<br>
![](res/Screenshot&#32;from&#32;2019-03-04&#32;21-51-48.png)<br>
![](res/Screenshot&#32;from&#32;2019-03-04&#32;21-51-57.png)<br>
![](res/Screenshot&#32;from&#32;2019-03-04&#32;21-52-05.png)<br>

https://cs.stackexchange.com/questions/29897/use-count-in-relational-algebra

> Referential integrity refers to the accuracy and consistency of data within a relationship. It requires that, whenever a foreign key value is used it must reference a valid, existing primary key in the parent table. For example, if we delete record number 15 in a primary table, we need to be sure that there’s no foreign key in any related table with the value of 15. We should only be able to delete a primary key if there are no associated records. So it will prevent - Adding records to a related table if there is no associated record in the primary table, Changing values in a primary table that result in orphaned records in a related table, Deleting records from a primary table if there are matching related records.

## Entity Relation Model:
- A non-technical design method works on conceptual level based on the perception of real world.
- Consists of collection of basic objects called entities and of relationship among there objects and attributes which define their properties.
- Free from ambigutes and provides a standard and logical way of visualizing data.
- Basically it is a diagramatic representation easy to understand even by non-technical user.
- Conversion of ER model to Relation model is simple.

ER model describes data as entity, relationship and attributes. An entity is a real world thing that has an independent existence. Entity may have physical existence or conceptual existence. eg - a particular person, car, book, house or a course, a department, a university, a job, etc. 3 markers of same company same appearance cannot be called entity (Independent existence) they are still objects. With each entity, a set of attributes are associated that describe the properties of that entity.

Entity type is defined as a collection of entities that have the same attributes.<br>
Entity set is the collection of all the entities of a particular entity type in a database at any point of time. Entity set is represented by rectangle.

Table of Relational Model, each values of student table is an entity while the student table is entity set.<br>
![](res/Screenshot&#32;from&#32;2019-03-05&#32;11-32-02.png)

Attributes are the units that describe the characterstics of entities such that each entity can be differentiated.
- For each attribute there is a set of permitted values called domains
- In ER diagram represented by ellipse or oval while in relational model by a seperate column.

Types:
1) Simple-Composite : Simple cannot be divided any further represented by simple oval. Composite can be divided further in simple attributes, oval connected to oval.
2) Single-Multivalued : Single can have only one value at an instance of time. Multivalued can have more then one value at an instance of time. Multivalued is double oval represented.
3) Stored-Derrived : Stored is how value is stored in the database. Derrived is how value can be computed in runtime using stored attributes. Derrived is represented by dotted. (Age is derrived by DOB or distance in google maps derrived by destination and source)

Relationship:<br>
Relationship is an assosiation between two or more entities of same or different entity set
- No representation in ER diagram as it is an instance or data
- In relational model represented either using a row in table

Relationship Type: a set of simmilar type of relationship<br>
- In ER diagram represented using diamond
- In relational model either by a seperate table or by seperate column (foreign key)
- Every relationship type has 3 components
    - Name
    - Degree
    - Cardinality Ratio/Participation Constraint<br>
![](res/Screenshot&#32;from&#32;2019-03-05&#32;14-46-42.png)<br>
![](res/Screenshot&#32;from&#32;2019-03-05&#32;14-46-59.png)<br>

Degree of a relationship set: Means number of entity set associated (participated) in a relationship set. Most of the relationship set in ER diagram are binary. Unary relationship is also possible like in above image student-student student can be a monitor

Mapping Cardinalities Ratio: Express the number of entities to which other entities can be related via a relationship. Can be used in describing a relationship set of any degree but is most useful in Binary relationship
- 1 : 1 (One to One) Entity of a set can relate atmost one entity of other set and vice versa. Atmost means there can be an entity not in relationship. Indian Citizen & Aadhar number
- 1 : N (One to Many) Indian Citizen & Mobile Number
- N : 1 (Many to One) Mobile Number & Indian Citizen
- M : N (Many to Many) Teacher & Students

In relationship representation 1 n will be written. Arrow will denote a one one relationship simple line means many

> Every one to one relationship is one to many or many to one or many to many relationship as well but not vice versa

Participation Constraint: Specifies weather the existence of an entity depends on its being related to another entity via a relationship type. These constraint specify the minimum and maximum number of relationship instances that each entity can/must participate in.<br>
Maximum Cardinality, It defines the maximum number of times an entity occurence participating in a relationship while Minimum Cardinality is the minimum number of times an entity occurence participating in a relationship.
- Partial Participation (Minimum cardinality = 0) Not bounded to be in a relationship
- Total Participation (Minimum cardinality > 0)
Example: A project employee relationship. Each project must have min 5 employee and max 12 employee. Each employee must be in atmost 2 projects. Here project min cardinality is 5 and max 12 while for employee its 0 and 2. Project to employee is total participation while employee to project it's partial participation. (Double line in total participation)

> The Strong Entity is the one whose existence does not depend on the existence of any other entity in a schema while a weak entity is the one that depends on its owner entity i.e. a strong entity for its existence. A weak entity is denoted by the double rectangle. ![](res/Screenshot&#32;from&#32;2019-03-05&#32;21-57-11.png)

Conversion to Relational Model:
- Converting Entity Sets to table: Simply put entity set as table and all entities as values
- Composite and multi valued attributes: Forget about main attribute (name forget take fname lname in table)
- Weak Entity set:
    - 1:1 - Include primary key attribute of strong entity set and all other attribute of weak entity set
    - M:N - take primary key of both
    - 1:N/N:1 - take all attributes of entity set it total participation and for other take primary key

![](res/Screenshot&#32;from&#32;2019-03-06&#32;01-17-36.png)

## Functional Dependency

The functional dependency is a relationship that exists between two attributes. It typically exists between the primary key and non-key attribute within a table.<br>

A functional dependency between two sets of attributes X and Y that are subsets if R specifies a constraint on the possible tuples that can form a relation state 'r' of R. The constraint is that, for any 2 tuples t1 and t2 in r that have t1[x] = t2[x] they must also have t1[y] = t2[y]

X → Y<br>
The left side of FD is known as a determinant, the right side of the production is known as a dependent.<br>
For example: Assume we have an employee table with attributes: Emp_Id, Emp_Name, Emp_Address. Here Emp_Id attribute can uniquely identify the Emp_Name attribute of employee table because if we know the Emp_Id, we can tell that employee name associated with it. Functional dependency can be written as: Emp_Id → Emp_Name

Types of functional dependencies - Trivial A B → A (returns what we already know), Non trivial A → B

Attribute Closure/Closure on attribute set: Attribute closure of an attribute set A can be defined as a set of attributes which can be functionally determined from it. denoted by f<sup>+</sup>
```
uss attribute ki pahuch kaha tak he
A → B, B → C
then A+ = A B C
A → B, C → D E, A C → F, D → A F, E → C F
then D+ = D A F B
```

Full functional dependency: Functional Dependency denoted by X → Y where X & Y are sets of attributes of R X → Y is said to be full FD iff there exists no functional dependency, denoted by A → X such that A is a proper subset of X A ⊂ X

Partial FD: .... if there exists some functional ....

Armstrong's Axioms:
- Axiom is a statement that is taken true and serve as a permise or starting point for further argument
- Armstrong axioms hold on every relational database and can be used to generate closure set.

Primary rules:
- Reflexivity - if Y ⊆ X then X → Y
- Augmentation - if X → Y then XZ → YZ
- Transivity - if X → Y & Y → Z then X → Z

We can prove secondary rules from primary rules

Secondary Rules:
- Union - X → Y & X → Z then X → Y Z
- Decomposition - if X → Y Z then X → Y & X → Z

> Union & Decomposition need to be done on right side, union we can do on left side but usse nuksaan hi hoga https://youtu.be/vs65S6Nku5g?list=PLmXKhU9FNesR1rSES7oLdJaNFgmuj0SYV&t=959

- Psuedo Transitive - if X → Y & W Y → Z then W X → Z
- Composite - if X → Y & Z → W then X Y → Y W

https://youtu.be/NeITRksKLzs?list=PLmXKhU9FNesR1rSES7oLdJaNFgmuj0SYV<br>
https://youtu.be/0XmHRycmrp0?list=PLmXKhU9FNesR1rSES7oLdJaNFgmuj0SYV<br>
https://youtu.be/o0GQQFu-5C0?list=PLmXKhU9FNesR1rSES7oLdJaNFgmuj0SYV<br>
https://youtu.be/_-F6QfdheEk?list=PLmXKhU9FNesR1rSES7oLdJaNFgmuj0SYV

During finding candidate keys we first find which attribute doesn't have any incoming relation then we take it first verifying through closure for finding candidate keys. Attributes inside the final candidate key are prime attributes and left over are non prime attributes.<br>
![](res/Screenshot&#32;from&#32;2019-03-05&#32;22-21-30.png)

## Normalization:
![](res/Screenshot&#32;from&#32;2019-03-05&#32;20-09-51.png)<br>
Idea: In the table studentInfo we have tried to store entire data about student<br>
Result: Entire branch data of a branch must be repeated for every student of the branch.<br>
Redundancy: When some data is stored multiple time unnessarily in a database.<br>
Disadvantages:
- Insertion, deletion and modification anomalies
- Inconsistency (data)
- Increase in data size and increase in time
Insertion Anomalie: like say civil dept me koi banda nahi toh info table me dept ki bhi nahi hogi.<br>
Deletion Anomalie: agar akela banda he dept ka usse delete nahi karsakte warna branch khatam<br>
Updatation Anomalie: update karna ho branch related kaa usse multiple jagah karna padega

Solution in Normalization. It is a logic of decomposing a table until the most optimal result is obtained. It is done on the basis of functional dependencies. Functional dependency can decompose till BCNF only for later on scenerios we need to consider lossy decomposition.<br>
![](res/Screenshot&#32;from&#32;2019-03-05&#32;20-23-51.png)

1NF implications:
- A table is said to be in 1NF if every cell contains atomic values. Value can be null.
- Every column should also contain values from the same domain.
- Order of rows or column is irrelevant
- Every column should have unique name

2NF implications:
- Check for 1NF then the table must not have partial dependency<br>
![](res/Screenshot&#32;from&#32;2019-03-05&#32;22-25-35.png)<br>
In the above example AB is the key and D is dependent on AB which is complete key so total complete dependency but for C it depends only on B not AB so it is in partial dependency so not in 2NF to make it in 2NF we will decompose it into two tables such that this property still holds.<br>
https://youtu.be/yIN6k57OB3U?list=PLmXKhU9FNesR1rSES7oLdJaNFgmuj0SYV

3NF implications:
- If it's in 2NF & has no transitive dependancy
- Transitive dependance is a functional dependency from A → B is called transitive if A, B are non-prime.<br>
https://youtu.be/9H4aJqYyd9s?list=PLmXKhU9FNesR1rSES7oLdJaNFgmuj0SYV

BCNF implications:<br>
![](res/Screenshot&#32;from&#32;2019-03-06&#32;00-29-09.png)<br>
Here in this example below, there's no partial dependancy and transitive dependancy so last is checking if right one is prime and left one can be prime as well as non prime. Here it is both prime in C → B so it's not in BCNF. If C would have been anything else which is a super key then we can ignore it<br>
![](res/Screenshot&#32;from&#32;2019-03-06&#32;00-30-20.png)<br>
https://youtu.be/mzxnbsmIRNw?list=PLmXKhU9FNesR1rSES7oLdJaNFgmuj0SYV