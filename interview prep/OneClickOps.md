# What problem does it solve?
* when port operation team receives incidents, L1/L2 engineers have to dig through historical case logs and SOPs to look for relevant solutions
* a decision-support system that combines Hybrid RAG over historical logs and SOPs with LLM reasoning so that the system engineer can just paste the incident description and immediately get the recommended solution. 

# Design Considerations
## What size is the text chunk, why this text chunk and have you tried other way? 
* document-level chunking, each chunk corresponds to one case logs/ SOPs, reason for this is that one case log corresponds to one resolution, breaking it into smaller chunks will break the semantic meaning. 
* for SOPs that grow significantly longer, will consider sliding window with overlaps

## What if text chunk gets really long?
* will contain a lot of unrelated sections => embedding dilution
* exceeding LLM context window => lead to hallucination
* will retrieve the right chunk but contains a lot of unrelated sections

## How would I do differently?
* use context-aware parent-child chunking strategy
* store the incident as a parent document -> split into smaller chunks according to symptoms, diagnosis, root cause and resolution.
* retrieve smaller chunks => return the corresponding parent document and nearby chunks

## How do you manage to keep the context of each chunk because sometimes the one sentences may be broken up into multiple chunks? 
* chunks is never split mid-sentence, so the actual meaning of the chunk is still preserved. 
## Why Qdrant and not supabase?
* reason for this is that Qdrant is built for lightweight and could be run locally, for a self-hosted MVP and for simplicity we chose Qdrant over Supabase.
* Supabase is only needed for capabilities like relational storage and authentication.
## How do you benchmark this?
* Used gpt to paraphrase around 20 incidents from the historical logs with known resolutions, then compare the top-k resolutions/SOPs received to verify the accuracy.

### Benchmark metrics:
* nDCG@k (Normalized Discounted Cumulative Gain at rank k): to evaluate the quality of a ranked list 
* Recall@k: evaluate the accuracy of retrieved chunk
* MRR (Mean reciprocal rank): Evaluate the ranking correctness of a chunk
## Why do you use BM25, any other solution to speed up the retrieval, and how do you justify 40% increase?
* BM25 acts as the initial gate, scan over the whole knowledge base to retrieve candidate vectors, run dense vector search on the shortlisted set of vectors.
* Benchmark against just the dense retrieval

### Initial plan:
* BM25 candidate generation → dense reranking of candidates → top-k documents 
* Downside: BM25 exact text-matching may remove relevant chunks 
### How would I do differently?
* Use BM25 & dense reranking in parallel (BM25 for exact text matching for error codes, equipment names & port numbers & dense reranking for semantic matching and paraphrases)

## Similarity score threshold?
* set arbitarily, below 0.6 the documents returned are loosely related to the queries

# What are some challenges faced?
* Out of distribution queries, sometimes no document may be returned and LLM may hallucinate. Tried prompt engineering to ensure that LLM only answers using documents retrieved and in the case where no documents are retrieved it can give its own suggestions but flag as non-verified
* Sometimes one query might require resolutions from multiple documents, current RAG pipeline doesnt store chunks that keep track of dependencies with other chunks, might consider LightRAG for future improvement
