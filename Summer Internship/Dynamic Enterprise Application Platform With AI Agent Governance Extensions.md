## How is it different from other framework?
* Bolt-on AI agent: built on different systems 
* AI-agent orchestration: workflows for both human and AI are different

## What's new?
* both AI and human work in the same context, so there is no need for switching contexts, reducing token usage
* runtime actor definition instead of predefined actor

## How does it implement confidence gating?
* threshold is calculated statically base on event type

## What may be lacking?
* Using json schema may not be scalable, in a more general setting, sometimes the schema is not purely flat but relational.
* Assuming both ai and human have a symmetric relationship, both have different modes of thinking and different shortcomings.
