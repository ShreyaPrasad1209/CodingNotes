# Software Engineering
## Introduction
- The nature and complexity of software have changed significantly. Applications used to run on single processor, recieve their input from linear source today are far more complex (more processors, different OS, etc).
- Improve the software development process in order to deliver good quality maintainable software in time and within budget.
- Major software industry problem - develop a bug free software "software crisis" harware keeps getting better and cheaper.
- Y2K problem (year format 1964 only 64 fault after 2000s), Patriot missile (timing error in clock non operational after 14 hours), rocket crash (sideway velocity stored from 64 bit to 16 bit number too big overflow error), windows XP (on release day added patch).
- Blame goes to software compaines - too rushed or too careless, software developers could not understand the importance of detecting and removing faults before customer experience. University for not teaching software engineering principles and practices.

> Software is more than programs. It consists of programs, documentation of any facet of the program and the procedures used to setup and operate the software system.

Reasons why it's difficult to improve software process:
- Not enough time: Unrealistic schedule. Companies often ship 1.0 and release 1.01 almost immediately to fix recently discovered bugs.
- Lack of knowledge: Do not seem familliar with technology or industry best practice.
- Wrong motivations: contractor influence
- Insufficient commitment<br>
![](res/Screenshot&#32;from&#32;2019-03-08&#32;16-18-41.png)

> Proper planning is required, milestone, suitable project model, quality assurance points, etc.

Hardware & Software Characterstics<br>
![](res/Screenshot&#32;from&#32;2019-03-08&#32;16-18-55.png)<br>
![](res/Screenshot&#32;from&#32;2019-03-08&#32;16-19-02.png)
- Software never wears out
- Software is not manufactured (One time development and continuous maintainance effort)
- Reusability (Hardware can be reused software have to be build from scratch in many cases)
- Software Flexibility

Types Of Software: System Software (OS, Drivers) Realtime Softwares (Weather Forecast) Embedded Software (Automobile) Buisness Software, Personal Computer Software, AI Software, Web based Software (HTML, Java, Perl), Engineering and scientific software (MATLAB). There are also Generic product or Customised products

Software Myths:
- Software is easy to change: Making changes without introducing errors is extremely difficult
- Computers provide greater reliability than the devices they replace
- Testing software of proving software correct can remove all errors
- Reusing software increases safety
- Software can work right the first time
- Software with more features is better software
- Aim is to develop working program (high quality, maintainable programs)
- Addition of more software engineers will make up the delay

> Measure provides quantitative indication of the extent, dimension siz, capicity, efficiency, productivity or reliability. Measurememnt is the act of evaluating a measure. A metric is a quantitive measure of the degree to which a system component or process possesses a given attribute. Process metric (productivity, quality, failure rate, efficiency, etc) Product metrics (size, reliability, complexity, functionality, etc.)

> Productivity may be measured as LOC (lines of code) / PM (Person Months)

## Software Development Life Cycle (SDLC)
The period of time that starts when a software product is conceived and ends when the product is no longer available for use. The software life cycle typically includes a requirement phase, design phase, implementation phase, test phase, installation and check out phase, operation and maintainance phase and sometimes retirement phase.

1) Build and Fix Model: Simple two phase model. Sitable for small programming exerices. Code soon becomes unfixable and unenhancable. There is no room for design or any aspect of development process to be carried out in a structured or detailed way. The cost of the development using this approach is actually very high as compared to the cost of a properly specified and carefully designed product. Maintainance of the product can be extremely difficult without specification or design documents.<br>![](res/Screenshot&#32;from&#32;2019-03-08&#32;16-42-38.png)
2) Waterfall Model: <br>![](res/Screenshot&#32;from&#32;2019-03-08&#32;16-43-58.png)
    - Understand the exact requirements of the customer and document them properly. Produce large document written in natural language SRS (Software Requirement Specification). It's a contract b/w the developer and customer. If developer fails to implement full set of requirements, it will be failure.
    - Goal is to transform requirements, into structure suitable for implementation. Overall software architecture is defined. SDD (Software Design Description) is result
    - Initially small modules are tested in isolation<br>
> Problems of waterfall model: Difficult to define all requirements at the beginning, not suitable for accomodating changes, working version is not seen until late, does not scale up for large projects. However if organization has experience in developing accounting systems then building new accounting system based on existing designs could be easily managed with waterfall model.
3) Increment Process Model:
    - Iterative Enhancement Model: Same as waterfall but conducted in several cycles giving release at end of every cycle. Requirement analysis then prioritize requirements.<br>![](res/Screenshot&#32;from&#32;2019-03-08&#32;16-57-49.png)
    - RAD (Rapid Application Development) Model: Continuous user participation ensures the involvement of user's expectations and perspective in requirement elicitation, analysis and design of the system. The process is started with building a rapid prototype and is given to user for evaluation.<br> ![](res/Screenshot&#32;from&#32;2019-03-08&#32;17-05-35.png)
    - Evolutionary Process Model: Iterative model just we don't need usable product at the end of cycle. Requirements are implemented by category rather then priority. Used in project with new technology.
4) Prototyping Model: First develop a working prototype<br> ![](res/Screenshot&#32;from&#32;2019-03-08&#32;17-10-16.png)
5) Spiral Model: Important software projects have failed because project risks were neglected & nobody was prepared when something unforeseen happened. <br>![](res/Screenshot&#32;from&#32;2019-03-08&#32;17-43-03.png)<br>During the first phase, planning is performed, risks are analyzed, prototypes are built, and customers evaluate the prototype. A more refined prototype is built, requirements are documented and validated, and customers are involved in assessing the new prototype. By the time third phase begins, risks are known and a somewhat more traditional development approach is taken. The focus is the identification of problems and the classification of these into different levels of risks, the aim being to eliminate high-risk problems before they threten the software operation or cost. An important feature of the spiral model is that each phase is completed with a review by the people concerned with the project. If the plan development fails then the spiral is terminated. The advantage of this model is the wide range of options to accomodate the good features of other life cycle models. It becomes equivalent to another life cycle model in appropirate situations. The spiral model has some difficulties that need to be resolved before it can be a universally applied life cycle model. These difficulties include lack of explicit process guidance in determining objectives, constraints, alternatives; relying on risk assesment expertise; and providing more flexibility than required for many applications.

Unified Process: It supports iterative development where project is developed through a series of short, fixed length miniprojects called iterations. Output of each iteration is tested and integrated. Sequential approach (waterfall) is not suitable due to changing requirements and uncertainities in software development, Iterative approach is definitely bettern than sequential approach and became the basis of unified process.
- Inception: Gathering and analysing requirements > planning and preparing a buisness case and evaluating alternatives for risk management > Estimating overall cost and schedule of project > Studying feasibility and calculating profitability of project.
- Elaboration: Development plan, revised risk document, An executable architectural prototype, Architectural description document, Use case model, Peiliminary user manual.
- Construction: Documentation Manual, Operational Manual, Test suits and outlines, A description of current release
- Transition: Transitioning the product to the customer delivering, training, supporting and maintaining the product. Product release, user feedback.

![](res/Screenshot&#32;from&#32;2019-03-08&#32;17-56-59.png)

## Software Requirement Analysis And Specification
Requirement engineering is one of the most crucial activity in the creation process.<br>![](res/Screenshot&#32;from&#32;2019-03-08&#32;17-58-40.png)
1) Requirement Elicitation: Requirements are identified with the help of customer and existing systems processes, if available.
2) Requirement analysis: Requirements are analysed to identify inconsistency, defects, omissions, etc. We describe requirements in terms of relationship and also resolve conflicts.
3) Requirement Documentation: SRS
4) Requirement Review: To improve the quality of SRS. Also called requirement verification.

Output of requirement engineering is requirement specification (Software+Hardware then System Req. Spec. Only software then SRS). Requirement specification must treat system as a black box. It must delineate inputs, outputs, the functional requirements that show external behaviour in terms of input, output and their relationship and non functional requirements and their constraints including performance, portability, and reliability.
- Requirements are difficult to uncover
- Requirements change
- Tight project schedule
- Communication Barriers
- Market driven software development
- Lack of resources

Type of requirements - Known requirements, Unknown Requirements (Forgotten by stakeholder), Undreamt Requirements (Stakeholder may not be able to think because of limited domain knowledge). Functional requirements describes what the software hase to do, often called product featuers. Non Functional requirements are mostly quality requirements that stipulate how well the software does what it has to do. Non functionality quality requirements that are especially importantto users include specifications of desired performance, availability, reliability, usability and flexibilty. Non functional requirements for develpers are maintainability, portability and testability. Functional requirements are directly related to customer's expectations for the acceptance of product however, non functional requirements may make customer happy and satisfied. These are important for success of any product.

> User requirements are written for the users and include functional and non functional requirements. Simple language should be used. The software terminologies, notations etc. should be avoided. Highlight the overview of the system without design characterstics.

> (APIs Data structures), Feasibility Test

**Requirement Elicitation**
- Interviews: After recieving the problem statement from the customer. the first step is to arrange a meeting with the customer. During the meeting or interview, both the parties would like to understand each other. Understand the customer's expectations. Interview may be open-ended or structured. In openended there's no preset agenda. Context free questions may be asked to understand the problem and to have and overview of the situation.
> Stakeeholders: Entry level personnel (not have sufficient domain knowledge, useful for fresh ideas and different views), Mid level stakeholders (better domain knowledge and experience. Know the complex, sensitive and critical area of the project), Managers or other stakeholders (their expectations may provide different but rich information for the software development), Users of the software (Only caution required is that they may be biased towards existing systems.)
- Brainstorming Sessions
- FAST (Faciliated Application Specification Technique): Simmilar to brainstorming objective is to bridge the expectation gap - a difference between what developers think they are supposed to build and what customers think they are going to get. In order to reduce expectation gap. Customers are developers who work together to understand the expectations and propose a set of requirements.
    - Each participant presents his/her lists of objects, services, constraints, and performance for discussion.
    - The combined lists for each topics are prepared by eliminating reundant entries and adding new entries
    - Combined list are again discussed
    - Once the consensus lists have been completed, the team is divided into smaller subteams, each works to develop mini-specifications for one or more enteries of the lists.
    - Each subteam then presents mini-specifications to all FAST attendees.
    - The team may raise an issue that cannot be resolved during the meeting and are considered later.
    - Each attendee prepares a list of validation criteria for the product/system and presents the list to the team.

> Normal Requirements (discussed with the customer), Expected Requirements (Maybe so obvious that customer does not explicitly state them), Exciting requirements (beyond customer's expectations)

The QFD (Quality Function Deployment) method has following steps:
1) Identify all the stakeholders e.g customers, users and developers. Also identify any initial constraints identified by the customer that affect requirements development.
2) List out requirements from customer; inputs, considering different viewpoints. Requirements are expression of what the system will do, which is both perceptible and of value to customers. Some customer's expectations may be unrealistic or ambiguous and may be translated into realistic requirements if possible.
3) A value indicating a degree of importance is assigned to each requirement on a scale of 1 (unrealistic) to 5 (very important).

**Requirement Analysis**
- Draw the context diagram
- Development of a prototype (optional) - Throw away prototyping or Evolutionary prototyping (prototype is built with the idea that it will eventually be converted into the final system)
- Model the requirements: This process usually consists of various graphical representations of the functions, data entities, external entities and the relationship between them. The graphical view may help to find incorrect, inconsistent, missing, and superfluous requirements. Such models include DFD, ER, Data Dictionary
- Finalise the requirements: Inconsistency and ambiguity has to be identified and corrected. Flow of data amongst various modules has been analysed. Now we finalised the requirements.

**Requirement Documentation**
Nature Of SRS:
- Functionality: What software is supposed to do
- External Interfaces: How does the software interact with the people, hardware, and other software
- Performance: What is speed, availabilit, response time, recovery time, etc
- Attributes: What are consideration for portability, correctness, maintainability, security, reliability, etc.

SRS should correctly define all the software requirements. A software requirement may exist because of the nature of the task to be solved or because of a special charactersitc of the project, Should not describe any design or implementation details. These should be described in the design stage of the project. Should not impose additional constraints on the software. These are properly specified in other documents such as a software quality assurance plan.

Characterstics of a good SRS - Correct, Unambiguous, Complete, Consistent, Verifiable, Modifiable, Traceable

**Requirement Validation**
- Plan review: Review team is selected and time and place for review meeting is fixed.
- Distribute SRS document: to all the members
- Read SRS document: Each member should read to find conflicts, omissions, incossitencies, deviations from standards and other problems.
- Organise review meeting
- Follow up actions
- Revise SRS document

> Problems occurs like - Requirement clarification, missing information, requirement conflict, unrealistic reqirement, security issue

## Software Project Planning
Size estimation: The estimation of size is very critical and difficult area of the project planning. It has been recognised as a crucial step from the very begining. The difficulties in establishing units for measuring size lie in the fact that the software is essentially abstract. It is difficult to identify the size of a system.<br>
- LOC (Lines Of Code): Not comment or blank line. There are some disadvantage of this simple method of counting. LOC is language dependent.
- Function Count: 