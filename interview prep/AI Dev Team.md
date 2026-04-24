# What problem does it solve?
* enterprise engineers waste time on SDLC coordination
* automate these tasks while keeping human in the loop, maximal agent coordination and minimal human interaction.

# Design Considerations
## How do you implement the sandbox? Is there any alternatives u have considered?
* Filesystem confinement, the agent is only allowed to work in the file directory that the user has given access to, any ../ commands are restricted.
* Write protection in place that forces the agents to edit only targeted regions of the files instead of overwriting the whole files 
* Other alternatives:
  * spinning up Docker for each of the agents but will increase latency
  * OS level protection such as executing as low-level priviledged user
## How do you ensure that the agent are constrained to its own role and not performing tasks outside of its role?
* Forced to use only tools from their tool box (hard enforcement)
* System prompt is appended to every agents' instructions to route to the chief orchestrator, stating the reasons for why they decline
* pipeline sequencing: first the chief orchestrator which can only delegate tasks and cannot execute task, then the PM which breaks down the tasks into requirements, scrum master then pubish the tasks, the 2 Devs then start working, followed by QA and CR. 
## How to make sure requirements are met? 
* Each development stages are gated, so users can choose to continue or choose to rework certain stages. There is also a savepoint mechanism that allows users to move back to the previous developmnent stages. 
## How do you benchmark this?
* We validated this by allowing the agents to build a real working calculator, while we dont have the metrics we have a proof of concept showing the pipeline works end-to-end. 

# Challenges Faced
# Sometimes might loop forever, how do I fix this?
* recalling the same tool over and over again:
  * explicit prompt engineering enforcing the agents not to call certain tools over and over again.
  * max calls on tools is 100, terminates after 100 calls, so the underlying principle is to make the tools calls idempotent 
