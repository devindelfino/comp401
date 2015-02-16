Project 03: Ethics in Computing - Safety-Critical Systems
=========================================================
*Devin Delfino*

Description
-----------
Safety-Critical Systems are complex systems predominantly controlled by computer software where failure of the system has severe negative consequences towards humans, lives, or the environment. Examples include space satellites, medical instruments, railway signalling, air traffic control, weapons systems, nuclear powerplantsthe precautionary principle says that if the consequences are unknown but are judged to have a high risk of being negative, it is better to not carry out the act., etc.

Notes for [Reference 1](http://cacm.acm.org/magazines/2000/4/7692-the-ethics-of-safety-critical-systems/fulltext)
-----------------------
###### General Notes

* software decisions are based more on economic reasons than safety reasons
* software errors occur more randomly and result in more unpredictable consequences (opposed to hardware failures)
* backup systems that can funtion as simply as possible are recommended in safety-critical systems
* development of safety-critical systems should aim to minimize risks
* theoretical and mathematical backgrounds are essential to make sure a safety-critical system is fully understood
* "Every engineer has limitations, and it is important that individuals recognize their own limitations, as well as those of others, and keep within their bounds of expertise."
* foundational knowledge of the mathematics and concepts behind an idea is extremely important (this is something that has been commonly found in the programming occupation)
* No special qualification are currently required for employees developing and maintaining software for safety-critical systems (only personnel with a great balance of skill, experience, expertise, and knowledge should contribute to these systems)
* college level computer science and software engineering programs should include more ethical and formal aspects, especially where knowledge of mathematical foundations are learned and applied to practical problems

###### Practices to Avoid

1. **Epideictic** - Avoid using particular techniques, notation, or programming languages just because it is a company standard. Before applying a specific approach to a problem, determine if it is necessary and the best fit.

2. **Hyberbole** - Do not settle on an approach simply because it is a formal method that has been claimed to be beneficial in the situation. Sometimes these claims are exaggerated, so be sure to take into account all techniques and methods that can be used to accomplish a task.

3. **Pistic** - Do not trust a tool or proof so much that you do not perform testing on the functionality.

4. **Oligarchy** - Have an expert accessible to aid while integrating new methods into a desing process to ensure everything is up to date and on the same page.

5. **Ephemeral** - Designing code to be reused in the future is important for long term cost benefits, but make sure it is consistently tested when deploying older code in new environments.

6. **Epexegesis** - Clear, understandable, and readable documentation is invaluable. Too much documentation can be just as problematic as too little.

7. **Maiandros** - Do not get stuck too long informally designing and diagraming a system. Introduce a formal way of testing (programming language or mathematical notation) to recognize specifications and catch more errors at an early stage.


Notes for [Reference 2](http://www.idt.mdh.se/utbildning/exjobb/files/TR0358.pdf)
-----------------------
###### General Notes

* increasing the safety of a system may hinder other favorable properties such as low cost, availability, usability, and performance
* the precautionary principle says that if the consequences of an action are unknown but are judged to have a high risk of being negative, it is better to not carry out the act.
* this principle encourages the search for safer alternative options and solutions
* software is considered 'safe' when it is impossible (highly unlikely) that it could produce an output that leads to a serious event like property damage, physical harm, etc.
* company and all employees contributing to a system are responsible for making an effort to produce a safe product

###### Problems with Software

1. problems arise with communication between two areas of expertise (engineers building software for an application that they have no background knowlegde about)
2. Incompleteness of requirements can lead to unwanted behaviour that wasn't distinguished in the requirements design
3. Complicated software can have the potential to go beyond known limitation since it can be sometimes too difficult to determine how it will perform in all situations
4. Changing the design of software to remove faults may introduce new faults that are difficult to detect


Objective
---------
Write a 3-5 page position paper accomplishing the following:

1. Identify the ethical problem. What is it? Why is it an issue?
2. Speak from varying perspectives on the issue. (software engineer, user experience)
3. Present my own thoughts and position on the topic

References
----------
1. [The Ethics of Safety-Critical Systems](http://cacm.acm.org/magazines/2000/4/7692-the-ethics-of-safety-critical-systems/fulltext)
2. [Ethics and Safety-Critical Software Systems](http://www.idt.mdh.se/utbildning/exjobb/files/TR0358.pdf)