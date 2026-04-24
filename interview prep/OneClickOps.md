# What problem does it solve?
* when port operation team receives incidents, L1/L2 engineers have to dig through historical case logs and SOPs to look for relevant solutions
* combines Hybrid RAG over historical logs and SOPs with LLM reasoning so that the system engineer can just paste the incident des and immediately get the recommended solution. 

# Design Considerations
## What size is the text chunk, why this text chunk and have you tried other way? 
* document-level chunking, each chunk corresponds to one case logs/ SOPs, reason for this is that one case log corresponds to one resolution, breaking it into smaller chunks will break the semantic meaning. 
* for SOPs that grow significantly longer, will consider sliding window with overlaps
## How do you manage to keep the context of each chunk because sometimes the one sentences may be broken up into multiple chunks? 
* chunks is never split mid-sentence, so the actual meaning of the chunk is still preserved. 
## Why Qdrant and not supabase?
* reason for this is that Qdrant is lightweight and doesnt require external dependency, for a self-hosted MVP and for simplicity we chose Qdrant over Supabase. 
## How do you benchmark this?
* Used gpt to paraphrase around 20 incidents from the historical logs with known resolutions, then compare the top-k resolutions/SOPs received to verify the accuracy.
## Why do you use BM25, any other solution to speed up the retrieval, and how do you justify 40% increase?
* BM25 acts as the initial gate, scan over the whole knowledge base to retrieve candidate vectors, run dense vector search on the shortlisted set of vectors.  
## Similarity score threshold?
* set arbitarily, below 0.6 the documents returned are loosely related to the queries

# What are some challenges faced?
* Out of distribution queries, sometimes no document may be returned and LLM may hallucinate. Tried prompt engineering to ensure that LLM only answers using documents retrieved and in the case where no documents are retrieved it can give its own suggestions but flag as non-verified
* Sometimes one query might require resolutions from multiple documents, current RAG pipeline doesnt store chunks that keep track of dependencies with other chunks, might consider LightRAG for future improvement
