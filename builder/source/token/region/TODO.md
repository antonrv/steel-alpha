

Current region implementation is incomplete but already practical, and is based on the following.

1. There are two main components : **guards** and **accesses**.

2. A guard is characterized by a set of accesses.

3. An access is characterized by the following properties.

### Vertical context :

  * array : Memory access is done as an indirection ptr[ expr ]
  * call : Memory access is done in the callee function.

### Expression kind :

  * Static : 

    Examples

    * affine : Can be characterized as an affine expression on loop/induction variables ( `eg i*X + j*Y + k*Z` )

    * non-affine : Cannot be characterized as an affine expression ( eg non-linear on loop/induction variables, `i*i`

    * Previous can be dynamic if the embedding variables are not guaranteed to be constant anywhere in the context. In this case, the range properties in the guard could not be statically inferred. If those variables belong to local embeddings, we could still guarantee mesh::tree access. If those variables belong to global embeddings, we wouldn't and we would need to use mesh::full backends emissions.

  * Dynamic :

    * indirect : expression is a value of something statically unknowable (eg ptr[ call(...) ], ptr[ ptr2[...] ]



...


The way we are building the accesses is very intrincated, noted by the existence of several constructors for different scenarios, eg:

* receiving global embeds of a sibling access with superior dimensions

* receiving global embeds of a downstream guard with superior dimensions

* receiving global and local embeds of a sibling access with superior dimensions

* not receiving anything.


The digestion is branched depending on these scenarios not only in constructors, but also in internal branches within constructors.
This overcomplicates the process, makes it error prone, and makes it hardly debuggable.

This was done in this way to directly build guards that are fully defined.


## Problem statement

Inputs:

* An application consisting on arbitrary operations on n-dimensional arrays.

* Written in a full sequential programming language.

* Written in a platform-agnostic way (ie block sizes or any other parameter are not meant to be set in advance).

Output:

* High performance execution of that application, in parallel, in any platform.






To achieve that we would need the following.

* Digestion of accesses does not depend on lateral relations, ie relations of an access with other accesses in the same function context.

* Digestion of accesses does not depend on its vertical relation (ie only if it is a 'call' vertical context).

* Instead, accesses are fully built (ie its properties are fully defined) from their expressions. Their relations (ie whether it has a downstream guard or not) are easily deducible too.

Note that the unique goal is to inject adequate statements during code translations, so that n-dim subregions can be safely and fastly accessed at runtime in parallel.

* Depending on these properties and their relations data is accessed in a mesh::direct, mesh::tree, mesh::single or mesh::full way.

mesh::direct require: all accesses are affine,  are all internally disjoint, have no offsets (ie addend not associated to any embed), can be expressed in terms of the same global embeds and local embeds, and all are disjoint wrt those embeds.. Runtime access is O(1).

mesh::tree require: all accesses are affine, can be expressed in terms of the same global embeds, but multiple local embeds. Runtime access is O(D·logn) with D dimensions and n number of accesses in the container.

mesh::single: there is a single access O(1), no concurrent access to that data possible.

mesh::full: the more conservative. n-dim accesses cannot be inferred statically, so this is the fallback case where the full region is protected against concurrent access. ( case of indirect access )

* With the new dim/matching.cpp algorithm we can easily check whether an arbitrary expression can be expressed in terms of a set of embeddings.


We will come back to this problem once we have a full proof of concept working (ie the runtime producing parallel executions).
