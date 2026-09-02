# An overview of what it is?
* It is a preliminary agent harness that simulates the SDLC
* There are 7 agents (Chief orchestrator, project manager, scrum master, 2 developers, 1 QA agent and 1 Code reviewer agent)
* The orchestrator agent main job is to dispatch the required agents at each development stages and to coordinate the interactions between different agents
* The user will input what they want to build, the chief orchestrators will first gather the requirements and clarify any assumptions.
* PM will then be dispatched and it will break down the tasks into implementation plan
* Scrum master will then assign the tasks to 2 developers
* Human gate in between development and the testing phases. Users can approve or ask for improvement.
* QA agent will then run the tests suites during the testing stage, will go back to development stage if test suites fail.
* code reviewer will then review the code in terms of code maintainability. 
# What problem does it solve?
* enterprise engineers waste time on SDLC coordination
* automate these tasks while keeping human in the loop, maximal agent coordination and minimal human interaction.

# Design Considerations
## How do you implement the sandbox? Is there any alternatives u have considered?
* Filesystem confinement (configuring file permission), the agent is only allowed to work in the file directory that the user has given access to, any ../ commands are restricted.
* Write protection in place that forces the agents to edit only targeted regions of the files instead of overwriting the whole files (prefer append-only over modification) (validate against an approved file and line scope)
* Other alternatives:
  * spinning up Docker for each of the agents but will increase implementation complexity and also increase latency.
  * OS level protection such as executing as low-level priviledged user
### What I would do differently for sandbox
1. Just preventing ../ is not enough, agent is able to use absolute path or a symbolic link that will point outside of the allowed workspace root. An alternative will be to have an allowed list of dir which the agents are able to access and validate the **canonical paths** on every file operations. [Application-level restrictions]
2. Give the agent a non-root user with minimal file permissions [OS-level restrictions]
## How do you ensure that the agent are constrained to its own role and not performing tasks outside of its role?
### Hard rule 
* Forced to use only tools from their tool box (hard enforcement)
* State enforcement: at certain states only specific agent roles are able to execute (can think of it as a state machine)
* orchestrator verifies the output schema and delegates the tasks to other agents
* System prompt is appended to every agents' instructions to route to the chief orchestrator, stating the reasons for why they decline
* pipeline sequencing: first the chief orchestrator which can only delegate tasks and cannot execute task, then the PM which breaks down the tasks into requirements, scrum master then pubish the tasks, the 2 Devs then start working, followed by QA and CR. 
## How to make sure requirements are met? 
* Each development stages are gated, so users can choose to continue or choose to rework certain stages. There is also a savepoint mechanism that allows users to move back to the previous developmnent stages. 
## How do you benchmark this?
* We validated this by allowing the agents to build a real working calculator, while we dont have the metrics we have a proof of concept showing the pipeline works end-to-end. ( Proof that it is an integration test and not a performance benchmark) 

# Challenges Faced
# Sometimes might loop forever, how do I fix this?
* recalling the same tool over and over again:
  * explicit prompt engineering enforcing the agents not to call certain tools over and over again.
  * max calls on tools is 100, terminates after 100 calls, so the underlying principle is to make the tools calls idempotent
## What I would do differently?
* Per agent and per state budget
* Having configurable maximum retry counts for each tool
* Using exponential backoff when retrying after a limit

