# Discrete Structures

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
