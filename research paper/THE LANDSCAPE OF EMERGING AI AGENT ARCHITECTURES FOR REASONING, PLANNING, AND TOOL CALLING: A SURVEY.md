## Problem
What are they trying to solve?
* limitations & capabilities of current sys, insights and suggestions for future improvement 

## Insight
What did I learn that I didn’t know before?
* When to use multi and when to use single? use multi when collaboration with different agents/users are needed and when the problem is not well defined.
* AI persona: the roles and the tools that AI agent can use
* Horizontal & Vertical archi: Horizontal means no leader agent
* Planning strategy: PlanLikeAGraph(PLaG)

### Single-Agent Architecture
**ReACT**, **RAISE** (Reasoning and Acting through Scratchpad(short-term memory) & Examples(long-term memory)), **Reflexion**: single-agent archi, instead of relying on gradient-based model update(reward), relies on verbal reflection. **AUTOGPT + P**: use to command robots in natural language. Combines Object detection, Object Affordance Mapping with planning from LLM. **LATS**: use tree and self-reflect
* need to do self-evaluation

* ReAct limitations: will loop over again and again, thus need human interaction to improve its effectiveness
* RAISE limitations: if the agent role not very well defined, might hallucinate and perform tasks outside of its role. Might also give wrong info. but can be solved via **fine-tuning** 
* Reflexion: non-optimal solution, uses sliding window so limited by the tokens
* AutoGPT + P: selecting the wrong tools, getting stuck in loops, lack human interaction to modify plan during execution, illogical explorations
* LATS: uses more computational resources for search algorithm and self-reflection, no tool calling and complex reasoning.

### Multi-Agent Architecture
* 3 stages: planning -> execution -> evaluation
* Team leadership, communication and dynamic team formation

* **Embodied LLM Agents Learn to Cooperate in Organized Teams.** : focuses on leadership & dynamic team structure, vertical level for collaboration tasks and horizontal for decision making
* **DyLAN** : focuses on dynamic team formation, evaluation to move top contributors to next round
* **AgentVerse**: recruitment, collaborative decision making, independent action making, eval. Make sure only useful/appropriate agents are working.
* **MetaGPT**: focus on solving chatter between different agents

* **Limitations**:
  1. easily affected by unsound feedbacks from other agents (Horizontal)
  2. if leader fail to send important information, then will cause confusion/hallucination

## Questions
What don’t I understand yet?
