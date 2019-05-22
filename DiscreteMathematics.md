# Discrete Mathematics

## Proposition
A proposition is a declarative sentence (that is, a sentence that declares a fact) that is either true
or false, but not both. Truth value (weather proposition is true or false) true = 1 false = 0 we can make truth table.<br>
Negation of preposition P is ~P i.e. “Michael’s PC runs Linux” becomes "Michael’s PC does not run Linux."<br>
> Conjuction (AND ^) Disjunction (OR v) Negation (NOT ~)

Compound Proposition is when one or more propositions are connceted through various connectivites is called compound proposition. "Rosses are red and violets are blue" and serves as connectivity between two proposition. Single unbreakable proposition is known as primitive proposition.<br>
- Tautology: Truth values are true for any truth value of variable
- Contradiction: Totally false truth values
- Contigency: Some are true some are false

> Two propositions are said to be in logical equivalence if they have same truth values

The statement p → q is called a conditional statement because p → q asserts that q is true
on the condition that p holds. “If I am elected, then I will lower taxes.” Biconditional statements p ↔ q is true if both p & q have same truth value. "You can take the flight if and only if you buy a ticket."

Let p be the statement “Maria learns discrete mathematics” and q the statement “Maria will
find a good job.” Express the statement p → q as a statement in English. “If Maria learns discrete mathematics, then she will find a good job.”

Law Of Algebra of proposition:
1) Idempotent Law: p v q ≡ p
2) Associative Law: (p v q) v r ≡ p v (q v r)
3) Commutative Law: p v q ≡ q v p
4) Distributive Law: p v (q ^ r) ≡ (p v q) ^ (q v r)
5) Identical Law: p v T ≡ T, p ^ T = p
6) Complement Law: p v ~p = T, ~T = F
7) Involution Law: ~~p = p
8) Demorgan's Law: ~(p v q) = ~p ^ ~q

CONVERSE, CONTRAPOSITIVE, AND INVERSE (p → q "If I study hard, I shall succed" "If it rains I get wet"):
- Inverse: ~p → ~q "If I don't study hard, I shall not succed" "If it doesn't rain I don't get wet"
- Converse: q → p "If I shall succed, I study hard" "If I get wet then it rains"
- Contrapositive: ~q → ~p "If I shall not succed, I don't study hard" "If I don't get wet then it doesn't rain"

Quanitfier: Quantifiers are words that refer to quantities such as ”some” or ”all” and tell for how many elements a given predicate is true.
- Existential (some, there exists or there is atleast one) ∃
- For all ∀

"There exists a man" - ∃(x) M(x)<br>
"Some men are clever" - ∃(x) (M(x) -> C(x))<br>
"Some real numbers are rational" - ∃(x) (N(x) -> R(x))<br>
"All graphs are connected" - ∀(x) [G(x) -> C(x)]<br>
"Not all graphs are connected" - ~∀(x) [G(x) -> C(x)]<br>
"Some graphs are not connected" - ∃(x) (G(x) -> ~C(x))<br>
"Some cats are black" - ∃(x) (C(x) -> B(x))<br>
"Somebody likes someone" - ∃(x)∃(y) P(x, y) here P(x, y) means x likes y<br>
"Everybody likes everybody" - ∀(x)∀(y) P(x, y)<br>
"Everybody likes someone" - ∀(x)∃(y) P(x, y)<br>
"There's someone liked by everybody" - ∃(x)∀(y) P(x, y)<br>

Predicates: Statement involving variables. a is less then b, 2 placeholder predicate Q(a, b)
> The statements that describe valid input are known as preconditions and the conditions that the output should satisfy when the program has run are known as postconditions

Rules Of Inference:
1) Simplication: p ^ q => p or p ^ q => q
2) Addition: p => p v q or q => p v q
3) p v q => ~p -> q
4) ~p => p->q
5) q => p->q
6) ~(p->q) => p
7) ~(p->q) => ~q
8) p, q => p ^ q -> conjuction
9) p v q, ~p => q -> disjunctive syllogism
10) ~(p ^ q), p => ~q -> conjuctive syllogism
11) p->q, p => q -> modus pones
12) p->q, ~q => ~p -> modus tollens or contrapositive
13) p->q, q->r => p->r transitive law
14) (p->q) ^ (r->s), p v r => q v s

Proof by direct method: first statement is assumed true<br>
Proof by contraposition method: assumed ~of both statements result<br>
Proof by contradiction: ~of statement<br>
Exhaustive proof and proof by cases: Proof by taking examples, generating cases and proofing cases<br>

## Relation
Let A and B be sets. Abinary relation from A to B is a subset of A×B. This relation can be represented with a zero one matrix.<br>
Maximum relation size can be NxM minimum is 0.<br>
Any relation out of MxN of cartesian product has option to either come in relation or not so total possible relation is 2^(mn)

> [complement] R<sup>c</sup> = { (a, b) | (a,b) ∈ AxB & (a, b) ∉ R}

> [inverse] R<sup>-1</sup> = { (b, a) | (a,b) ∈ R}

> A relation R on a set A is called reflexive if (a, a) ∈ R for every element a ∈ A. No. of reflexive relations possible is 2^(n2-n) Derrivation is simple we have n by n matrix we fixed 1 in diagonal we can have any value at other place.

> A relation R on a set A is called ir-reflexive if (a, a) ∉ R for every element a ∈ A. (Ek bhi diagonal element nahi chahiye eesme reflexive me saare hone chahiye)

> A relation R on a set A is called symmetric if (b, a) ∈ R whenever (a, b) ∈ R, for all a, b ∈ A. A relation R on a set A such that for all a, b ∈ A, if(a, b) ∈ R and (b, a) ∈ R, then a = b is called anti symmetric. (kisi ke liye symmetric pair naa ho matlab same ho toh chalega)

> Asymmetric relation is for all a, b ∈ A, (a, b) ∈ R and (b, a) ∉ R (Antisymmetric diagonal allow karta tha ye wo bhi nahi karta)

> A  relation R on  a  set A is  called transitive if  whenever (a, b) ∈ R and (b, c) ∈ R, then (a, c) ∈ R, for all a, b, c ∈ A. (Agar a-b he b-c he toh a-c hona chahiye)

![](res/Screenshot&#32;from&#32;2019-04-30&#32;22-30-09.png)<br>

> All 3 reflexive, symmetric, transitive then it's equivalence relation. If reflexive + anti-symmetric + transitive then it's partial ordering.

> Let R be a relation from a set A to a set B and S a relation from B to a set C. The composite of R and S is the relation consisting of ordered pairs (a, c), where a ∈ A, c ∈ C, and for which there exists an element b ∈ B such that (a, b) ∈ R and (b, c) ∈ S. We denote the composite of R and S by S◦R.<br>
R<sup>n+1</sup>=R<sup>n</sup>◦R

> The relation R = {(1,1), (1,2), (2,1), (3,2)} on the setA = {1,2,3} is not reflexive. How can we produce a reflexive relation containing R that is as small as possible? This can be done by adding (2,2) and (3,3) to R. This new relation is reflexive closure. Same way we have symmetric and transitive closure.

> Let R be an equivalence relation on a set A. The set of all elements that are related to an element a of A is called the equivalence class of a. The equivalence class of a with respect to R is denoted by[a]<sub>R</sub>.<br>
[x] = {y | y ∈ A & (x, y) ∈ R}

https://youtu.be/CmZzZsaof8g?list=PLmXKhU9FNesTpQNP_OpXN7WaPwGx7NWsq

## Hess Diagram
Partial order ko further study karne ke liye we use it<br>
https://www.youtube.com/watch?v=KVdzsIjLTQk&list=PLmXKhU9FNesTpQNP_OpXN7WaPwGx7NWsq&index=17<br>
https://www.youtube.com/watch?v=fMgSzYBdz1I&list=PLmXKhU9FNesTpQNP_OpXN7WaPwGx7NWsq&index=18<br>
https://www.youtube.com/watch?v=fJ2tJgSMAA4&list=PLmXKhU9FNesTpQNP_OpXN7WaPwGx7NWsq&index=19<br>
https://www.youtube.com/watch?v=VY_1fMdaa18&list=PLmXKhU9FNesTpQNP_OpXN7WaPwGx7NWsq&index=26<br>
https://www.youtube.com/watch?v=Ul7cCuJzjVQ&list=PLmXKhU9FNesTpQNP_OpXN7WaPwGx7NWsq&index=30<br>
https://www.youtube.com/watch?v=4sQWtiGmV5c&list=PLmXKhU9FNesTpQNP_OpXN7WaPwGx7NWsq&index=34

Distributive: If it has at most 1 complement for every element (follows distributive law for every permutation of elements)<br>
Complemented: Atleast 1 complement for every element<br>
Boolean Algebra: Both distributive and complemented means exactly 1 complement ho

## Graphs
> Graph is a structure defined as G(V, E) where V is a set of vertices, V = {V1, v2, V3 ... Vn} and E is a set of edges, E = {E1, E2, E3 ... En}

> Directed Graph (edges use ordered pair representation), Undirected Graph (edges use unordered pair representation)

> Adjacent vertex: If two vertex are joined by the same edge they are called adjacent vertex.<br>
Adjacent edge: If two edges are incident on same vertex they are called adjacent edge.<br>
Self loop: Edge having same vertex<br>
Parallel edge: When more then one edge assosiated with a given pair of vertices such edges are called parallel edges.

![](res/Screenshot&#32;from&#32;2019-05-01&#32;15-01-58.png)<br>

> Finite graph: A graph with finite no. of vertices as well as finite no. of edges is called finite graph.<br>
Null graph: A graph where vertex set is non-empty but edges set is empty is called null graph.<br>
Trivial graph: A graph where vertex set contains only one vertex and edge set is empty is called trivial graph.<br>
Complete graph: A graph where there's an edge between every vertex (K<sub>n</sub>) n means number of vertices. Total edges then is n*(n-1) / 2

> Pendant vertex (degree 1) Isolated vertex (degree 0)

> Handshaking Lemma: Sumation deg(i) = 2 * |E| = summation odd deg(i) + summation even deg(i)

> 𝛿(G) is minimum degree out of all vertices in the graph G. 𝛿(G) * |V|  <= 2|E|

> Δ(G) is maximum degree out of all vertices. Δ(G) * |V| >= 2|E|

https://www.youtube.com/watch?v=07Q6N-WeaGM&list=PLmXKhU9FNesS7GpOddHDX3ZCl86_cwcIn&index=9<br>
https://www.youtube.com/watch?v=3-oUfRnXl_g&list=PLmXKhU9FNesS7GpOddHDX3ZCl86_cwcIn&index=10

> Regular Graph: A graph with all vertices of equal degree i.e. k then it's a k-regular graph.

> Bipartite Graph: A graph G(V, E) is called bipartite if it's vertex set V(G) can be partitioned into two non-empty disjoint subsets V<sub>1</sub>(G) and V<sub>2</sub>(G) in such a way that each edge e ∈ E(G) has it<br>A simple graph is bipartite if and only if it is possible to assign one of two different colors toeach vertex of the graph so that no two adjacent vertices are assigned the same color.<br>
https://www.youtube.com/watch?v=yelUNp4l740&list=PLmXKhU9FNesS7GpOddHDX3ZCl86_cwcIn&index=13

> Walk: A walk is defined as a finite alternating sequence of vertices and edges, beginning and ending with vertices such that each edge is incident with the vertices preceding and following it. No edge appear more than one in a walk, a vertex however may appear more than once. When a walk begins and ends at same vertex it is closed walk.

> Path: An open walk in which no vertex appears more than once is called a path.

> Connected graph: A graph is said to be connected when there is a path between every pair of vertex.

> Euler Circuit/Cycle: A closed walk which visit every edge of the graph once. A graph with such cycle is called Euler Graph. If it's an open walk then it's Open Euler walk and such graph is semi-euler graph.

https://www.youtube.com/watch?v=fePkCuunnjk&list=PLmXKhU9FNesS7GpOddHDX3ZCl86_cwcIn&index=16

> Hamiltonian Cycle: In a connected graph is defined as a closed walk that traverse every vertex of G exactly once, except starting/ending vertex.

https://www.youtube.com/watch?v=uJUuRE3Itb0&list=PLmXKhU9FNesS7GpOddHDX3ZCl86_cwcIn&index=19<br>
https://www.youtube.com/watch?v=M0xA9P8QToU&list=PLmXKhU9FNesS7GpOddHDX3ZCl86_cwcIn&index=20

> Isomorphish: Two graphs are said to be isomorphism if they are perhaps the same graphs just drawn differently with different names i.e. they have identical behaviour for any graph properties. (formally) Two graphs G1 and G2 are said to be isomorphic if they are one-to-one correspondance between their vertices and edges, and incident relationship is preserved.

https://www.youtube.com/watch?v=fm6KCmG5OME&list=PLmXKhU9FNesS7GpOddHDX3ZCl86_cwcIn&index=22

> DIRAC’S THEOREM If G is a simple graph with n vertices with n ≥ 3 such that the degree of every vertex in G is at least n/2, then G has a Hamilton circuit.

> ORE’S THEOREM If G is a simple graph withnvertices withn≥3 such that deg(u)+deg(v) ≥ n for every pair of non adjacent vertices u and v in G,  then G has  a Hamilton circuit.