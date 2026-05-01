# Master Synthesis — INFO B302: Introduction à la démarche scientifique (IDS)

## Course identity and pedagogical framework

- **Course code:** INFO B302 — Introduction à la démarche scientifique (IDS)
- **Lecturer:** Xavier Devroey (xavier.devroey@unamur.be), University of Namur
- **Lecturer background:** Search-based Software Engineering, search-based software testing, model-based testing, software product lines testing, software testing, DevOps and test automation, software variability modelling, software normalization assessment and improvement (SNAIL lab — https://snail.info.unamur.be/)
- **Lab mission:** "Advance the state-of-the-art and practice of software engineering to improve software reliability by considering quality assessment and testing in both their human and technical contexts."

### Format and modalities

- **Form:** seminar; central thread is the production of a Master thesis in computer science: **réfléchir** (reflect), **élaborer** (elaborate), **communiquer** (communicate)
- **Group work:** groups of 3 students; deliverables are produced in **English**
- **Final report:** a **registered report** (pre-registration report) compiled from the deliverables across the term
- **Final grade:** individual; based on participation, evaluation of the pre-registration report, and an oral defence at the exam
- **Plagiarism (REE Article 81):** any use of others' ideas, formulations, or graphical representations — whether translated or paraphrased — without explicit and distinct citation. Teachers may control for plagiarism (which they do in IDS). Sanctions: 0/20 for the evaluation, possibly 0/20 for the entire course unit, and in serious or repeated cases, escalation to the dean/jury president per Article 77 §2/§3. Reference: https://www.unamur.be/plagiat
- **ChatGPT and similar tools:** must be used carefully; cf. Micode "La Fabrique à Idiots" (https://youtu.be/4xq6bVbS-Pw)

### Pedagogical objectives

- Discover what a scientific approach is by carrying one out yourself
- Learn to reflect on the scientific approach
- Develop reflective analysis: examine your own actions, build a critical mind, explain and argue your steps
- Prepare for the master's thesis process

---

# Part I — What is science?

## Definitions

- **Cambridge Dictionary:** "(knowledge from) the careful study of the structure and behaviour of the physical world, especially by watching, measuring, and doing experiments, and the development of theories to describe the results of these activities."
- **Le Robert:** "ensemble de connaissances, de travaux d'une valeur universelle, ayant pour objet l'étude de faits et de relations vérifiables, selon des méthodes déterminées (comme l'observation, l'expérience, ou les hypothèses et la déduction)."
- **Wikipedia:** "Science (from Latin *scientia* — 'knowledge') is a systematic enterprise that builds and organizes knowledge in the form of testable explanations and predictions about the world."

## The nine rules of science (Hengl & Gould 2006)

- Scientific knowledge needs to be built on **arguments and proofs** — not on beliefs or authority.
- Even the most pessimistic truth is better than fiction.
- There is **no democracy in science**: all can be wrong, and a single person can be right.
- Pluralism and open discussion, even speculation, need to be allowed.
- Everything is a priori possible; the issue is only **how probable** it is.
- Scientific proofs need to be built through research experiments that are **repeatable and unambiguous**.
- The results of research experiments need to be reported in an **unbiased, clear, concrete, coherent and logically-structured** way.
- Researchers need to be able to report on new knowledge in a **popular, open-minded** way.
- Science neither has a final goal, nor final theories.

Reference: Hengl, T., Gould, M., 2006. *The unofficial guide for authors (or how to produce research articles worth citing)*. EUR 22191 EN, Office for Official Publications of the European Communities — ISBN 92-79-01703-9.

## The world of science (actors and relationships)

The system is composed of seven interacting entities; the diagram links them through funding, employment, management, publication and reporting flows.

| Actor | Description |
|---|---|
| **Researchers** | People who professionally conduct research experiments |
| **Research groups** | Groups of researchers working on similar topics, meeting at scientific events |
| **Research organizations** | Universities, research centers, private companies (R&D divisions) |
| **System of science** | National and international organizations: members, structure, rules, evaluation criteria |
| **Research publications** | Articles and books published by scientific publishers — communicate new, original knowledge |
| **(Commercial) scientific companies** | Publishers and scientific information providers (also Sci-Hub — illegal) |
| **Funding bodies** | Fund researchers and groups via projects/scholarships |

### Researcher roles

| Type | Funding | Notes |
|---|---|---|
| Professors (Assistant / Associate / Full) | Tenured vs non-tenured | Career path |
| Researchers and postdocs | Project / scholarship | Tenured vs non-tenured |
| PhD students | Project / scholarship; may be teaching assistants or industrial PhDs | |
| Research technicians | Employees of the university | |

Reference directory: https://directory.unamur.be/entities/inf

### Research-group scales

| | Local | International |
|---|---|---|
| Small | SNAIL (snail.info.unamur.be) | SSBSE (ssbse.info) |
| Large | NaDI (nadi.unamur.be) | SIGSOFT (sigsoft.org) |

### Publication portals
- https://researchportal.unamur.be
- https://scholar.google.com
- https://dblp.uni-trier.de

## Relationships in the world of science

- Researchers **work for** research organizations and are **part of** research groups.
- Research groups **manage** research publications.
- Funding bodies **fund** researchers (who **apply for funding**).
- Researchers **report findings** in research publications, which scientific companies **publish**.
- The system of science evaluates and structures all of the above.

---

# Part II — How science works (epistemic engine)

## From empirical knowledge to theory

Science iterates: starting from a single hypothesis (e.g., **Genetic algorithms vs. Random** for white-box test generation), the researcher repeats comparisons across other approaches (vs. Symbolic, vs. Concolic, vs. Fuzzing) and across factors (programming languages, benchmarks, configurations, etc.). Aggregating these comparisons leads to a **theory** that **explains** and **predicts**.

## Testing theory through empirical evaluation

- Start from an existing theory
- Make predictions
- Test empirically
- Either invalidate the theory (or not)

## The demarcation problem

- **Drives:** state-of-the-art drives the formulation of new research questions
- **Feeds:** results from empirical evaluations feed the state-of-the-art
- The demarcation problem distinguishes scientific from non-scientific knowledge claims; it sits at the interface between what is known and what is investigated.

## Worked example: Benchmarking Java unit test generators

A canonical illustration of the full cycle (https://arxiv.org/abs/2106.07520):

| Step | Content |
|---|---|
| **Domain** | Java programs — white-box unit test cases generation (Java source files → Generator XYZ → Unit tests) |
| **Related work — pseudo-random** | Pacheco et al., "Finding Errors in .NET with Feedback-directed Random Testing" (ISSTA '08); Pacheco & Ernst, "Randoop: Feedback-directed Random Testing for Java" (OOPSLA '07); Pacheco et al., "Feedback-directed random test generation" (ICSE '07) |
| **Related work — evolutionary** | Lin et al., "Graph-Based Seed Object Synthesis for Search-Based Unit Testing" (ESEC/FSE '21); Vogl et al., "EvoSuite at the SBST 2021 Tool Competition"; Almasi et al., "An Industrial Evaluation of Unit Test Generation: Finding Real Faults in a Financial Application" (SEIP@ICSE '17); Rojas et al., "A detailed investigation of the effectiveness of whole test suite generation" (EMSE 2016) |
| **Tools** | Randoop (randoop.github.io/randoop), EvoSuite (evosuite.org) |
| **Research questions** | RQ1 How does XYZ perform vs pseudo-random and evolutionary? (RQ1.1 branch coverage; RQ1.2 fault-finding) — RQ2 Which factors influence XYZ? (RQ2.1 different class types; RQ2.2 different configurations) — RQ3 Can developers integrate XYZ tests into existing test suites? |
| **Methodology — data collection** | Empirical evaluation; benchmarks Defects4J and SF110; choices about number of classes, executions per class, configurations |
| **Methodology — data analysis** | Compare branch coverage and mutation score; visualization with boxplots; statistical tests + effect-size measures (Arcuri & Briand 2014, *A Hitchhiker's guide to statistical tests for assessing randomized algorithms in software engineering*, STVR 24(3), DOI 10.1002/stvr.1486) |
| **Results** | Friedman's test ranking (Kifetew, Devroey, Rueda 2019, SBST): T3 rank 1 score 2.30; EvoSuite rank 2 score 2.38; Randoop rank 3 score 2.51; Tardis rank 4 score 3.73; Sushi rank 5 score 4.09 — T3, EvoSuite and Randoop statistically better than Sushi/Tardis (Conover's procedure) |
| **Limitations** | Limited classes under test (representativity); limited executions (luck); limited configurations; tool implementation may have bugs; reproducibility |
| **Research perspectives** | Combine XYZ with another approach; compare with manually written tests; evaluate against other benchmarks |

| Tool | Friedman rank | Score | Statistically better than |
|---|---|---|---|
| T3 | 1 | 2.30 | Sushi, Tardis |
| EvoSuite | 2 | 2.38 | Sushi, Tardis |
| Randoop | 3 | 2.51 | Sushi, Tardis |
| Tardis | 4 | 3.73 | — |
| Sushi | 5 | 4.09 | — |

---

# Part III — The State-of-the-art

## Why does it matter?

- **For research:** "I wisely started with a map" (J.R.R. Tolkien). The state-of-the-art defines a **map of the research area** that directs the work — which families of techniques exist, which underlying theories ground them, how they work, how effective they are, for which kinds of problems.
- **For researchers:** "Publish or Perish." Funding, hiring, group reputation, project competitiveness, and editorial roles are decided through a least common denominator across actors: **how to evaluate research performance** of researchers, groups, institutions and projects.

## Bibliometrics

### For researchers

- **Citations:** number of times another paper cites one of the author's papers
- **H-index:** the largest *h* such that *h* papers each have at least *h* citations (e.g., 14 papers cited at least 14 times → h = 14)

### For journals (and conferences)

- **Impact factor:** average frequency at which articles in the journal are cited.
  - Formula: **Impact Factor = Citations(Y) / (Pubs(Y-1) + Pubs(Y-2))**
- **Conference rankings:** http://portal.core.edu.au/conf-ranks/
- Source IDs: https://www.scopus.com/sourceid/18650

### Why it matters to researchers

- Credit other researchers and acknowledge their ideas — because their career depends on it.
- Things are slowly changing.

## Reform initiatives

### San Francisco Declaration on Research Assessment (DORA)

- https://sfdora.org/read/
- **General recommendation:** do not use journal-based metrics (e.g., Journal Impact Factors) as a surrogate measure of an individual research article's quality, an individual scientist's contributions, or in hiring/promotion/funding decisions.
- Specific recommendations for funding agencies, institutions, publishers, and metrics organizations.
- Signed by 26,000+ people and organizations (sfdora.org); on Bluesky (@DORAssessment) and LinkedIn.

### For researchers (DORA actions)

- When on hiring/funding/tenure/promotion committees, base assessment on **scientific content**, not publication metrics.
- Cite **primary literature** rather than reviews, to give credit where due.
- Use a **range** of article metrics and indicators on personal/supporting statements as evidence of impact.
- Challenge research-assessment practices that rely inappropriately on Journal Impact Factors; promote and teach best practice that focuses on the value/influence of specific outputs.

### Coalition for Advancing Research Assessment (CoARA)

- https://www.coara.org and https://www.unamur.be/fr/recherche/euraxess/coara
- **Status options:** Signatory → optional Member; activities include: endorse publicly, achieve change, join communities, have a voice (Working Groups, National Chapters), network and learn.
- **Signatory:** publicly signal willingness to reform; **Member:** levels up at any time, no membership fees, participates in governance and decision-making.

## State-of-the-art structure in a paper

The state-of-the-art typically combines two sections.

### Background

- Introduces any element necessary to understand what the research is about
- **Basic concepts** (e.g., test case, genetic algorithms)
- **Focus of the research** (e.g., search-based test case generation)
- **Previous work** in the area that the research relies on (e.g., test case encoding, DynaMOSA)
- Assumes general knowledge of the broader research area (e.g., software engineering)
- Organized from general to detailed, dives progressively into the topic

Example structure:

    2. Background
      1. The traditional single-target approach
      2. Linearly independent path-based search (LIPS)
      3. Many-Objective Sorting Algorithm (MOSA)
      4. Dynamic Many-Objective Sorting Algorithm (DynaMOSA)
      5. Whole-suite approach with archive strategy (WSA)
      6. Many Independent Objects (MIO)

### Related work

Describes related research and how the current research **differs**:

- Similar approach for a different problem (e.g., genetic algorithms for test amplification)
- Same problem with a different approach (e.g., symbolic execution for unit test generation)
- Same problem, same approach, different goal (e.g., deployment of automated test case generation in industry)
- Same problem, same approach, same goal (e.g., a replication study)

The related-work section typically:
- Compares to one's own previous work and directly related work
- Compares to what is done in the community at large
- Describes a directly related study (description, summary, positioning)
- Describes related work in the large and positions the current study

Reference example: A. Panichella, F.M. Kifetew, P. Tonella, *LIPS vs MOSA: A replicated empirical study on automated test case generation*, SSBSE 2017, pp. 83–98, DOI 10.1007/978-3-319-66299-2_6.

## Citing sources

### Why cite

- Show your reader (i.e., peers) you've done proper research
- Be a responsible scholar — give credit to other researchers (their career depends on it)
- Avoid plagiarism (publications carry a copyright)
- Allow your reader to track down the sources you used

### What to cite

- Facts, figures, ideas, or other information that is not common knowledge
- Ideas, words, theories, exact language used by another person
- Another person's exact words must be **quoted and cited**
- When in doubt, cite

### How to cite

- Citations uniquely identify a published work; include a **DOI** whenever possible
- Located at the end of the document or in footnotes
- A citation contains: author name(s), titles of books/articles/journals, date of publication, page numbers, volume and issue numbers (for articles)
- Citations look different depending on what is cited and the style — pro-tip: use **LaTeX and BibTeX**

Reference: https://libguides.mit.edu/citing

---

# Part IV — Bibliographic search ("Fantastic publications and where to find them")

## How to find publications — wrong vs right scenarios

| Scenario | Approach | Outcome |
|---|---|---|
| 1 | Did not do the activity | Participation graded continuously — not viable |
| 2 | Pasted full bibliographic reference into Google | One result: a 129-page PDF about theology |
| 3 | Searched the article title in Google | Several results — but article costs $14.95 |
| 4 | Searched on **Google Scholar** | Single correct entry, with free PDF |

## How to find publications — the systematic way

A full SLR cycle, applied to the example "What is the current state-of-the-art of automated test case generation":

- Define the question (e.g., focus on white-box test case generation)
- Do a **systematic search** of the literature; identify relevant studies
- Assess the **quality** of the identified studies
- **Synthesize** data from selected studies (qualitatively or quantitatively)
- **Report** findings, including the full process followed
- Outputs example: "Most literature concerns search-based approaches; few case studies on industrial deployment; …"

## Systematic Literature Review (SLR)

### Goals

- Summarise existing evidence concerning a treatment or technology (e.g., empirical evidence of benefits and limitations of an agile method)
- Identify gaps in current research
- Provide a framework/background to position new research activities
- Examine to what extent empirical evidence supports/contradicts theoretical hypotheses; assist generation of new hypotheses

### Three-phase SLR protocol

| 1. Plan the review | 2. Conduct the review | 3. Document the review |
|---|---|---|
| 1. Specify research questions | 1. Identify relevant research | 1. Write review report |
| 2. Develop review protocol | 2. Select primary studies | 2. Validate report |
| 3. Validate review protocol | 3. Assess study quality | |
| | 4. Extract required data | |
| | 5. Synthesise data | |

### Advantages

- Well-defined methodology reduces likelihood of biased results (does **not** protect against publication bias in primary studies)
- Provides information about effects of phenomena across many settings and methods:
  - Consistent results → robust, transferable phenomenon
  - Inconsistent results → sources of variation can be studied

### Disadvantage

- Considerably more effort than a traditional literature review

## Identifying relevant literature — the pragmatic way

### Literature search engines

| Type | Engines |
|---|---|
| General-purpose | Google Scholar (scholar.google.com); Microsoft Academic (academic.microsoft.com); Scopus (scopus.com) |
| Publisher | ACM Digital Library (dl.acm.org); IEEEXplore (ieeexplore.ieee.org); ScienceDirect (sciencedirect.com); Springer Link (link.springer.com) |

### Search-string anatomy

- **Keywords** — e.g., `(test OR testing) AND ("search-based" OR "evolutionary computation")`
- **In** — title, abstract, keywords, full paper, …
- **Authors**
- **Publication year**

### Identifying relevant keywords

- From a general description (like topic statements provided in class)
- From an informal list of papers (provided by other researchers; collected from a workshop)
- From a formal list of papers (existing systematic literature reviews / mapping studies — these also describe the search strings used)

### The PICOC framework (for keyword construction)

| Element | Question | Example |
|---|---|---|
| **P**opulation | Who/what is the target affected by the intervention? | Computer science students with little to no training on literature reviews |
| **I**ntervention | What is done on the population? | Course on bibliographic search |
| **C**omparison | What are the alternatives? | None in this case |
| **O**utcome | What is the result of the intervention? | Improved understanding of how to conduct a literature review |
| **C**ontext | In what context does the intervention take place? | Computer science program |

### Building the search string — iterative loop

- Identify an initial set of keywords
- Build/update the search string and run the search
- Identify additional keywords from titles, abstracts, introductions, backgrounds, related-work sections of returned papers
- If new relevant publications appear, repeat; otherwise stop with the final set
- **For deliverable D2:** report the search engine and the full and final search string

## Inclusion and exclusion criteria

### Content-based criteria

- Relevant to the considered research domain
- Describes elements of the **background** (anything necessary to understand the research)
- Describes relevant **related work**:
  - Similar approach for a different problem
  - Same problem, different approach
  - Same problem, same approach, different goal
  - Same problem, same approach, same goal

### Meta-data-based criteria

- Peer-reviewed vs grey literature (non-peer-reviewed)
- Type of publication: books; research articles (short paper / full paper); master/PhD theses; technical reports
- Venue: conferences vs journals

### Application procedure

- Read title, abstract, keywords
- Decide if the paper is relevant
- In case of doubt, read the introduction and conclusion
- Track decisions (e.g., in a spreadsheet)
- **For D2:** include peer-reviewed research articles only; track and report decisions

## Snowballing

- **Goal:** identify additional publications by walking the citation graph
- **Backward (cited by the paper):** prior work — references list
- **Forward (citing the paper):** derivative work — via a literature search engine
- **Citation graphs** are used to identify research communities, are built from data collected in literature search engines, and help identify seminal works (https://www.connectedpapers.com/)

## Precision and recall

- **Precision:** number of relevant articles among those returned by the search strategy
- **Recall:** number of relevant articles found among all relevant articles that exist
- The set of relevant elements is **unknown** — an approximation is used

### Worked example (assuming 40 relevant papers)

| Strategy | Results | Relevant | Precision | Recall |
|---|---|---|---|---|
| Initial search (IS) | 250 | 20 | 8% | 50% |
| + snowballing 1 (SB1) | 250 + 500 | 20 + 10 | 4% | 75% |
| + snowballing 2 (SB2) | 750 + 100 | 30 + 3 | 3.8% | 82.4% |
| + snowballing 3 (SB3) | 850 + 20 | 33 + 0 | 3.8% | 82.3% |

Plotted on a precision-vs-recall plane, four quadrants emerge: **lots of work / high coverage**, **little work / high coverage**, **lots of work / low coverage**, **little work / low coverage**. There is no universally "best" point; the optimum depends on the goal.

### Trade-off rules

- High precision and high recall is **not possible** simultaneously
- **Background and related work:** requires a representative set of publications; focus on most-cited references first
- **Literature review:** aim for largest recall possible
- **Systematic literature review:** aim for largest recall and discuss strategies to achieve it

## Pitfalls to avoid

### Predatory journals and publishers

- Charge publication fees to authors without checking quality
- Fake conferences exist
- **Solution:** check the journal isn't on https://beallslist.net; verify the editorial board / conference organisers are well-known
- Famous example: "Cyllage City COVID-19 Outbreak Linked to Zubat Consumption" (American Journal of Biomedical Science & Research, 2020) — a fictional / joke paper that nevertheless got published, linking SARS-CoV-2 to consumption of Zubat (a Pokémon), with fabricated author affiliations (e.g., "Department of Diagnostic Medicine, Princeton-Plainsboro Teaching Hospital" — a reference to the TV show *House M.D.*) and fictitious geography ("Kalos region, France"). It illustrates how predatory venues fail to perform the most elementary sanity check.

### Search-engine pitfalls

- **Google Scholar:** indexes everything — including grey (non-peer-reviewed) literature and irrelevant papers
- **Scopus:** cleaner database, but not always up-to-date with the latest publications
- **Solutions:** combine multiple search engines; confirm publications via https://dblp.uni-trier.de

### Wrong keywords

- Different communities address the same topic with different keywords (e.g., **feature** in software product line engineering vs **configuration option** in software architecture)
- Different communities address different topics with the same keyword (e.g., **feature** in requirements engineering vs in machine learning)
- **Solution:** ask researchers from different domains; select papers from different research communities

### Problems with the search strategy

- **Wrong scope size** — Solution: adjust the scope after reading a few research papers on the topic of interest
- **Inclusion/exclusion criteria are too vague** — Solutions: formulate **binary** criteria; cross-check by asking another researcher to apply them
- **Don't know where to start with keyword selection** — Solution: ask a senior researcher in the field for relevant publications

---

# Part V — Research questions and hypotheses

## How science works (in slogan form)

- It all starts with a **research question**
- Focuses on the topic under research
- Based on the **state-of-the-art**
- Sets the scope of the study
- Drives the **research protocol**
- Is answered in the **conclusion**

## Building a research question — five-step funnel

| Step | What to do | Example |
|---|---|---|
| Context | State the broad context | Automated test case generation |
| General research topic | Pick a topic in the context | (Automated test case generation) |
| State-of-the-art | Survey to narrow down to a niche | Search-based, fuzzing, symbolic, … → search-based software testing for Java |
| Identify a research problem | Choose what gap to address | Evaluation of a new search-based test generation approach XYZ for Java |
| Formulate the research question | Phrase it precisely | How does XYZ compare to the state-of-the-art regarding its fault-finding capabilities? |
| Sub-questions / Hypothesis | Refine for clarity | (See below) |

## Categories of research questions

### Describing and exploring

- What are the characteristics of X (in context Y)?
- How has X evolved over time (in context Y)?
- What are the main factors in X?
- How has X dealt with Y?

### Explaining and testing

- What is the relationship between X and Y?
- What is the role of X in Y?
- What is the impact of X on Y?
- How does X influence Y?
- What are the causes of X?

### Evaluating and acting

- What are the advantages and disadvantages of X (in context Y)?
- How effective is X (for task Y)?
- How can X be achieved (in context Y)?
- What are the most effective strategies to improve X (in context Y)?
- How can X be used in Y?

Reference: https://www.scribbr.com/research-process/research-questions/

## Quality criteria for research questions

### Focused and researchable

- Focuses on a single topic and problem; defines the scope
- Refinement example:
  - ✗ What testing approaches exist?
  - ◯ What testing approaches exist for crash reproduction?
  - ✓ What automated testing approaches can be used for crash reproduction?
- **Answerable** using primary or secondary data — qualitative, quantitative, or existing studies
- Clearly indicates the criteria used; avoid subjective words like *good*, *bad*, *better*, *worse* — use a **measurable** definition
- Refinement example:
  - ✗ Is XYZ better than the state-of-the-art for test case generation?
  - ◯ How does XYZ compare to the state-of-the-art?
  - ✓ How does XYZ compare to the state-of-the-art regarding its fault-finding capabilities?

### Feasible and specific

- Answerable within practical constraints (time, resources, access to data)
- Uses specific, well-defined concepts; avoid vague language
- Clearly indicates **what, who, where, when**
- Refinement example:
  - ✗ What effect does social media have on people's minds?
  - ◯ What effect does daily use of social media have on attention span?
  - ✓ What effect does daily use of Twitter/Instagram/9Gag/… have on the attention span of bachelor students?

### Complex and arguable

- Cannot be answered with **yes/no** (no space for investigation/discussion); avoid "Can <anything/anybody> do <anything>?" — likely to earn a 0/20
- Cannot be answered with easily found facts (Wikipedia-level) — must require original data, synthesis, interpretation, argument
- Provides scope for debate and deliberation; results should be interpreted

### Relevant and original

- Addresses a problem **relevant** to your field (gap in existing knowledge — including replication of results) — hence the importance of bibliographic search
- Contributes to a topical social or academic debate; produces knowledge future researchers/practitioners can build on (also applies to fundamental research)
- Has not already been answered — should have novelty: a new angle, a specific aspect, etc.

## Construction frameworks

### PICOT (clinical research / evidence-based)

| Letter | Question |
|---|---|
| **P**atient/Population/Problem | Who or what is the patient, population or problem? |
| **I**ntervention | What action or treatment is being considered? |
| **C**omparison or control | What other interventions should be considered? |
| **O**utcome or objective | What is the desired or expected outcome? |
| **T**ime frame | How long until the outcome? |

#### PICOT example

- P: Java classes
- I: Generate unit tests using XYZ
- C: Generating unit tests using A, B, and C
- O: Compare fault-finding capabilities
- T: Time budgets of 1, 3, and 5 minutes
- **Final question:** How does the approach XYZ compare to A, B, and C regarding its fault-finding capabilities with time budgets of 1, 3, and 5 minutes?

Reference: https://onlinenursing.duq.edu/blog/formulating-a-picot-question/

### FINER checklist

| Letter | Criterion |
|---|---|
| **F**easible | Is it within the researcher's ability to investigate? |
| **I**nteresting | Is it interesting to the researcher, peers, and community? |
| **N**ovel | Does answering it bring new insights or confirm previous results? |
| **E**thical | Does answering it respect ethical and legal standards of the researcher and institution? |
| **R**elevant | Is it relevant to the scientific community (and the larger public)? |

## Sub-research questions and hypotheses

### Sub-research questions

- Refine a research question to clarify the scope; lift remaining ambiguities
- Example: "How does XYZ compare to the state-of-the-art regarding its fault-finding capabilities?" can decompose along several definitions of *fault-finding*:
  - **Fault-finding = coverage + mutation score:**
    - How does XYZ compare regarding the line coverage of generated tests?
    - How does XYZ compare regarding the mutation score of generated tests?
  - **Fault-finding = real faults:**
    - How does XYZ compare regarding the number of faults detected by generated tests?
  - **Fault-finding = developers' ability to identify faults:**
    - How does XYZ compare regarding the time required by developers to identify the root cause of a failing test?

### Hypotheses

- Refine a research question to clarify the scope (alternative or complement to sub-questions)
- Examples (same RQ):
  - XYZ produces tests with **higher line coverage** than A, B, and C
  - XYZ produces tests with **higher mutation score** than A, B, and C
  - Developers using XYZ require **less time** than developers using A, B, or C to identify the root cause of a test failure
- Hypotheses **drive data analysis** — typically statistical analysis of quantitative data to **reject** a hypothesis
- Reference: Arcuri & Briand 2014, *A hitchhiker's guide to statistical tests for assessing randomized algorithms in software engineering*, STVR 24(3): 219–250, DOI 10.1002/stvr.1486

---

# Part VI — Research methods

## The research-method onion

Source: Saunders, Bristow, Thornhill & Lewis (2019), *Understanding research philosophy and approaches to theory development*, in *Research Methods for Business Students* (8th ed.), Pearson Education, pp. 128–171. Concentric layers, from outer to inner:

- **Philosophy** (outer)
- **Approach**
- **Strategy**
- **Choice**
- **Time horizon**
- **Techniques and procedures** (inner)

## The methodology question

Given the RQ "How does XYZ compare to A, B, and C regarding its fault-finding capabilities in Java programs with time budgets of 1, 3, and 5 minutes?", the method must answer:

- **Why?** (rationale)
- **On what?** (scope)
- **Measure?** (variables)
- **How?** (procedure)

The dual aim is:

- **Maximize confidence** in the findings — what confidence? what threats? how?
- **Decrease threats to validity** — "it depends!"

## Threats to validity (illustrated via DynaMOSA optimization studies)

Reference example: A. Panichella, F.M. Kifetew, P. Tonella (2018), *Automated Test Case Generation as a Many-Objective Optimisation Problem with Dynamic Selection of the Targets*, IEEE TSE 44(2): 122–158, DOI 10.1109/TSE.2017.2663435.

### Context

- White-box automated test case generation for Java; uses genetic algorithms to generate a test suite maximizing a given set of coverage criteria (line, branch, weak mutation, …)
- Building test sequences and test input data that cover specific objectives (lines, branches)
- **Existing algorithms** consider objectives one at a time **or** aggregate all objectives into a single fitness function
- **MOSA:** Many-Objective Sorting Algorithm — all not-yet-satisfied objectives considered in parallel
- **DynaMOSA (objective):** Dynamic Many-Objective Sorting Algorithm — all **reachable** not-yet-satisfied objectives are considered in parallel

### Research questions

- RQ1 How does DynaMOSA perform compared to alternatives on **branch coverage**?
- RQ2 How does DynaMOSA perform compared to alternatives on **statement coverage**?
- RQ3 How does DynaMOSA perform compared to alternatives on **strong mutation coverage**?
- RQ4 How do preference criterion and Pareto dominance affect DynaMOSA's effectiveness?
  - RQ4.1 Effectiveness of DynaMOSA's Pareto-based ranking alone (without preference criterion)
  - RQ4.2 Effectiveness of DynaMOSA's preference criterion alone (without Pareto-based ranking)

### Threats — what could go wrong

| Threat type | Example | Consequence |
|---|---|---|
| **External validity** | Classes used for the evaluation are not representative | Findings cannot be generalized |
| **Internal validity** | Parameter values used for the baseline and DynaMOSA are not adequate | Unidentified factors can influence the results |
| **Internal validity** | Genetic algorithms rely on randomness | Luck can influence the results |
| **Construct validity** | Measures do not capture the intended purpose | Wrong assumptions lead to wrong conclusions |
| **Conclusion validity** | Comparison does not take the data distribution into account | Wrong assumptions about the data distribution lead to wrong statistical conclusions |

## Methodology — the discipline

- **Definition:** the study of research methods
- **Provides:** a framework for scientific research; helps define a research method
- **Standardizes** practices to increase confidence in results and reduce threats to validity
- **Enables reproducibility** in different contexts
- **Supports** the emergence of new research methods

## Onion layer 1 — Philosophy (epistemology: how is knowledge obtained?)

### Positivism

- Knowledge is **objective** and obtained by hypothesis testing
- Rigorous, controllable method
- No interpretation of the observations
- The "why" is irrelevant
- **Quantitative** empirical methods
- Founder: Auguste Comte (1798–1857)

### Interpretivism

- Social phenomena cannot be studied with a positivist stance — studying human beings by human beings cannot be objective
- Researchers have their own perceptions and interpretations; knowledge is built from interpretation
- **Qualitative** methods
- Quote (Morpheus, *The Matrix* 1999): "What is real? How do you define 'real'? If you're talking about what you can feel, what you can smell, what you can taste and see, then 'real' is simply electrical signals interpreted by your brain."

### Pragmatism

- Multiple stances, best viewed in terms of their practical usages
- **Pragmatic maxim:** "Consider the practical effects of the objects of your conception. Then, your conception of those effects is the whole of your conception of the object."
- A scientific concept or theory should be evaluated by **how effectively it explains and predicts** phenomena, as opposed to how accurately it describes objective reality
- Founder: Charles Peirce (1839–1914)

## Onion layer 2 — Approach: deductive, inductive, abductive

A triangle relates **Theory** (top) to **Reality** (bottom), through **Generalization** (left) and **Hypothesis** (right), with observations on the bottom corners.

| Approach | Direction | Logic |
|---|---|---|
| **Inductive** | Observations → generalization → theory | From data to theory |
| **Deductive** | Theory → hypothesis → observations | From theory to data |
| **Abductive** | Observations → hypothesis (best explanation) | Inference to the best explanation |

## Onion layer 3 — Strategy

### Experiment

- Measure the effects of an intervention on a population
- **Independent variables** — explanatory/predictor
- **Dependent variables** — outcome to measure
- Controlled environment (in lab)

### Survey

- Collect information from a subgroup of a population
- **Sampling strategies:** random, opportunistic, stratified, …
- Used to **explore** (identify important constructs), **describe** (tell what is happening), or **explain** (test theory)

### Case study

- Focus on a phenomenon, individual, group, or organization
- Gain deep understanding
- Used to explore, describe, or explain
- Relies on several techniques to collect data at different points in time

### Action research

- **Problem-driven**; introduces an action in an environment and studies its effects
- Aims to contribute to **research** (expanding scientific knowledge) **and practice** (solving a practical problem)
- **Iterative cycle:** Diagnosing (identifying/defining the problem) → Action planning (alternative courses of action) → Action taking (selecting a course of action) → Evaluating (studying consequences) → Specifying learning (general findings) → back to Diagnosing

### Grounded theory

- Develop a **new theory** from (qualitative) data
- **Iterative process:** identify important categories and relationships; collect more data until **saturation**
- Pipeline: Initial coding → (Induction) Categories ↔ Theoretical sampling, Constant comparison → (Abduction/Induction) Tentative theory → (Deduction) → Theory ↔ Abduction

### Ethnography

- Study an individual, a group, or an organization in a **detached** way; **no intervention**
- **Controlled** ethnography — define tools and observation protocols
- **Or uncontrolled**

### Archival research

- Examine existing documents (historical archives) to draw conclusions
- Examples: project reports, source code history, issue tracking systems, build history
- Comparable to systematic literature reviewing
- See MSR — Mining Software Repositories: https://conf.researchr.org/series/msr

## Onion layer 4 — Choice (methods)

### Quantitative methods

- Focused on quantitative data (numbers)
- Highly-structured tools to collect data: questionnaires (close-ended questions), well-defined metrics
- Large sample size

### Qualitative methods

- Focused on textual, visual, audio data
- Understand concepts, opinions, or experiences; gather in-depth insights
- Data collection: observations, interviews, texts, images, videos
- Relies on **coding**:
  - **Inductive coding:** Data → group in themes → develop codes
  - **Deductive coding:** Data + existing coding → code the data

### Mono-method, multi-methods, mixed-methods

- **Mono-method:** quantitative **or** qualitative
- **Multi-methods:** several quantitative or several qualitative
- **Mixed-methods:** quantitative **and** qualitative

### Five purposes for combining methods

| Purpose | Description |
|---|---|
| **Triangulation** | Check whether results from several methods converge |
| **Complementarity** | Use different methods for different parts of the research |
| **Initiation** | Discover contradictions to reframe the research questions |
| **Development** | Use the results of one method to develop the other |
| **Expansion** | Expand the breadth and range of research |

## Onion layer 5 — Time horizon

### Cross-sectional

- Measure a construct **once** (at time t)

### Longitudinal

- Measure the **same construct** at several time intervals (minutes, hours, days, years)
- **Sampling types:**
  - **Panel:** sample of people
  - **Cohort:** sample of people having a common feature
  - **Retrospective:** based on historical records

## Onion layer 6 — Techniques and procedures

### Data collection — what to specify

- Which data source?
- When is it collected?
- How is it collected?
  - **Questionnaires:** open-ended or close-ended; existing or new
  - **Interviews:** interview plan — structured / semi-structured / unstructured
  - **Automated tools:** tool + metrics + configuration

### Data analysis — what to specify

- **Coding scheme:** existing or new
- **Statistical analysis:** description of the procedure; checks on data distribution; checks for p-values
- **Cross-validation**
- Recommended reading: Arcuri & Briand 2014, https://onlinelibrary.wiley.com/doi/10.1002/stvr.1486

## Empirical Standards (for SE research)

- https://acmsigsoft.github.io/EmpiricalStandards/docs/
- **Standardizes peer-reviewing**
- Authors **declare** their research methods
- Reviewers receive a **specific checklist** matched to the method
- **Goal:** reduce review time and biases

---

# Part VII — Peer reviewing

## Where to submit a paper

A paper packages: context → general research topic → state-of-the-art → research question(s) → sub-RQs → hypotheses → protocol → data → analysis. The choice of venue depends on these.

### Submitting to a conference

- Conference proceedings in computer science are typically peer-reviewed (**not always** the case in other fields)
- Scope of the paper is **limited**
- Content fits in **8–10 pages**
- Topic must fit the conference scope:
  - **General conferences** (e.g., ICSE — https://conf.researchr.org/home/icse-2022)
  - **Specialised** conferences/symposiums/workshops, including co-located events

### Submitting to a journal

- Scope of the paper is **broader**
- Content fits in **more than 8–10 pages**
- Pick the right journal:
  - General research area (e.g., software engineering)
  - Specialised topics (e.g., software testing)

### Conference vs journal — comparison

| Aspect | Conference | Journal |
|---|---|---|
| Speed | Relatively fast (3–5 months) | Longer (6–12 months) |
| Iterations | One shot | Intermediate revisions possible |
| Outcome | Presentation of the work at the conference | Need to submit the published paper to a journal-first track |

## Conference review process

### Submission

- Author submits the paper
- Author **declares conflicts of interest (COI)**

### Conflict of Interest (COI) — ACM definition

> A COI occurs when a person's objective judgment is — or is perceived by a reasonable observer to be — compromised by an existing relationship, affiliation, or connection to a person whose work they must evaluate.

Concrete COI triggers:

- Notable personal or professional rivalry / animosity (publicly known or not)
- The lifelong relationship between PhD student and PhD supervisor
- Personal or family relationships that would reasonably cause others to doubt impartiality
- Potential for financial gain or significant recognition (personally or for a close associate / family member)
- Within the **last two years or reasonably expected within the next year**:
  - Working closely together (same institution, company, organization, or team)
  - Supervisor/Supervisee relationship
  - Funder or program-manager / awardee relationship
  - Recipients of joint funding or significant professional collaboration
  - Joint authorship of an archival publication (e.g., an item with a DOI)

### Bidding, assignments and review (Program Committee perspective)

- **PC chairs** assign papers to reviewers
- Reviewers (PC members) **bid** by indicating review preferences
- Each reviewer **reviews assigned papers and gives a score**
- Reviewers **discuss the paper** with other reviewers

### Decision and program

- Based on reviews and discussions, with usually **at least 3 different reviewers**
- The paper can be: **Accepted** to be included in proceedings, **Rejected**, or **Conditionally accepted**
- PC chairs make the program: distribute paper presentations between sessions, invite keynote speakers, etc.

### Scale — examples

| Conference | PC chairs | PC members | Submissions | Reviews | Per PC member |
|---|---|---|---|---|---|
| ICSE 2022 Technical Track | 2 | 188 | 691 | 691 × 3 = 2073 | ~11 |
| ICSE 2024 Technical Track | 2 | 238 | 1079 | 691 × 3 = 3147 | ~14 |

Reviewing is **free of charge**.

## Journal review process

| Step | Actor | Action |
|---|---|---|
| 1 | Author | Submits paper to a journal |
| 2 | Editor in chief | Assigns to associate editor |
| 3 | Associate editor | Sends requests to potential reviewers |
| 4 | Reviewers (3 or more) | Send reviews |
| 5 | Associate editor | Sends recommendation |
| 6a | Editor in chief | Accepts the paper for publication |
| 6b | Editor in chief | Rejects (with or without permission to resubmit) |
| 6c | Editor in chief | Requests a major or minor revision |

## Anonymity regimes

| Regime | Authors know reviewers? | Reviewers know authors? | Notes |
|---|---|---|---|
| **Single-anonymous** | No | Yes | — |
| **Double-anonymous** | No | No | Authors must double-blind their paper |
| **Triple-anonymous** | No | No | Reviewers also do not know who the other reviewers are |
| **Open review** | — | — | Reviews may be signed or not, and are published with the paper |

## Reviewing — Rule number one: nothing personal

- It is about the **research** and only about the research
- **As an author:** never take it personally
- **As a reviewer:**
  - Write a review about the **paper**, not about the **authors** — "the authors should describe" → "the paper should describe"
  - Leave personal feelings and beliefs out — avoid "I find this topic interesting"
- **As PC chair / associate editor:** take care of the **quality of reviews**
- **End goal:** improve the paper

## ICSE Technical Track review criteria

The criteria below are taken from ICSE 2022 review guidelines. They form the standard rubric used in IDS deliverable D6.

### Soundness

- The extent to which the paper's contributions and/or innovations address its research questions, supported by rigorous application of appropriate research methods.
- The paper should answer the questions it poses, and do so with **rigor in its research methodology** (including choice of methodology and procedures). This is an important difference between research papers and other knowledge-sharing forms (e.g., experience reports), and the source of the certainty researchers can offer.
- **Soundness is relative to claimed contributions.** If a paper claims causality but its method only shows correlation → grounds for critique. But if a paper only claims correlation and that correlation is a notable discovery → critiquing it for not demonstrating causality is **inappropriate**.
- **Extent of evaluation required is relative to the novelty of ideas:**
  - A novel idea with great potential can make a very valuable paper even with only **preliminary evaluation**
  - An incremental idea might need more support

### Significance

- The extent to which the paper's contributions can impact the field of software engineering, and under which assumptions. **(New for ICSE; stronger than in previous ICSEs — taken seriously.)**
- Impact relates to advances in the practice of software engineering: less costly, more maintainable, more reliable, more reusable, safer, more secure, more usable software (non-exhaustive).
- It is the authors' responsibility to **explain and interpret** the significance of their contributions, why they matter, what their potential impact will be, and under which assumptions.
- **For reviewers:**
  - Take the perspective of the targeted stakeholder; assess technical contributions in light of all involved costs and risks; weigh reported utility against required effort for setup and maintenance
  - Assess technical contributions not only by their evaluation results but also by the potential impact of underlying ideas
  - Welcome insights about practice (notably industry)
  - Consider that the path toward impact may be long, winding, and subject to assumptions
  - Consider that impact can result through methodological contributions
  - Be cautious about accepting a paper that has little significance
  - Dare to fight for papers that can be significant even if they have other weaknesses — no novel work is perfect from the start

### Novelty

- The extent to which contributions are sufficiently original with respect to the state-of-the-art.
- Grounded in adequate review of prior work; up to authors to convince the reviewer that discoveries advance knowledge — by shedding more light on prior work or adding a significant new idea.
- A possible audience is sufficient for publication (the PC does not perfectly reflect the broader audience).
- **Inappropriate critiques in isolation:**
  - Avoid penalizing because a single paper was already published on the topic — discoveries accumulate over many papers
  - Avoid penalizing immature work that contributes a really new idea for not yet having everything figured out
  - Avoid penalizing because results are not generalizable enough or only done in a specific context — generalizability takes time, some qualitative work doesn't intend to generalize
  - Avoid dismissing investigations of phenomena you personally don't like (e.g., "I hate object-oriented languages, this work doesn't matter")
  - Avoid penalizing because the paper adds only a few data points — such data can be hard to obtain and thus valuable
  - **Welcome independent replications** of previous work — they shed more light on certainty and validity. Do not penalize for "only" being a replication.
  - Do not reject papers just because they have negative results — check whether they are original w.r.t. state-of-the-art
  - Do not reject because the novel idea is simple — simple ≠ trivial; some of the best ideas are simple
  - Do not reject because you can imagine another (yet non-existing) technique that could have solved the problem
- **Related work:** papers should cite relevant related work and explicitly show how it relates. After reading the paper, the reviewer should feel more informed about the related literature.
  - Identify related work the authors have missed and include it in the review
  - Missing a paper that would not dramatically change the paper is **not sufficient grounds for rejecting** — citations can be added prior to publication
  - Focus on missing related work that would significantly alter research questions, analysis, or interpretation
- **Grey literature** (non-peer-reviewed: arXiv preprints, theses, blog posts, tech reports) **cannot be taken into account for judging novelty**:
  - Do not downgrade or reject because of an inadequately cited non-peer-reviewed paper
  - Do ask authors to point to such works as informative for readers
  - However, if a published technique is in widespread use (as a tool, method, or product), the submission must be novel with respect to this **state of practice**

### Verifiability and transparency

- The extent to which the paper includes sufficient information to understand how an innovation works, how data was obtained, analyzed, and interpreted, and how the paper supports independent verification or replication.
- This aims to check that the described research is **recoverable**. Reviewers should understand most key details about how authors conducted their work, made their invention possible, or inferred research findings from collected evidence.
- **Key for replication and meta-analysis** of studies underpinned by positivist or post-positivist approaches; for interpretivist work, key for evaluating qualitative work.
- Focus critiques on omissions of research process or innovation details that would significantly alter judgement of the paper's validity or credibility of results.
- **Welcome** tools and data that are available and usable at reviewing time
- If the paper contains sufficient detail, then data is **secondary**
- Welcome work whose authors made extra efforts to make it replicable and verifiable
- Avoid penalizing a paper for not describing every detail (recognize that some details are more important than others, and space is limited)
- Avoid asking authors to write substantially new method details unless space is available within length restrictions
- **Avoid penalizing papers only because their data is not available** — see Open Science Policies

### Presentation

- The extent to which the paper's quality of writing meets ICSE's high standards: clear descriptions, adequate use of English, absence of major ambiguity, clearly readable figures and tables, adherence to formatting instructions.
- Papers must be clear, concise, and comprehensible to diverse audiences.
- Recognize that not all authors are fluent English writers — but if language issues make the paper not comprehensible, it is not yet ready for publication.
- **Welcome:** honest discussions on assumptions, limitations, and novelty; detailed explanations that allow others to build on the work
- **Avoid:** penalizing for easily fixable spelling/grammar issues; penalizing a sufficiently clear paper because it could be clearer; penalizing for not using all available page count (it is okay if a paper is short but significant); asking for more detail without checking there is space — provide concrete suggestions for what to cut; penalizing for not following a particular paper structure or order of sections

## Recommendation and scoring

### Recommendation

- "Based on the criteria above, this paper should be published at ICSE."
- Decide how strongly you believe the paper should be accepted/rejected, **assuming authors make modest minor revisions** that you and other reviewers request before publication.
- Papers that meet **all** criteria should be **strongly accepted** (this does not imply the paper is perfect).
- Papers that fail to meet most criteria should be **strongly rejected**.

### Scores (Identify-the-Champion convention)

| Score | Meaning |
|---|---|
| Accept | This paper should be accepted |
| Weak accept | This paper may be accepted, but I will not fight for it |
| Weak reject | This paper may be rejected, but I will not fight against it |
| Reject | This paper should be rejected |

- To get a paper accepted, **at least one reviewer must champion** it — an explicit Accept score is not required; a champion can also emerge in discussion.
- Scores are revealed to authors during the **author response period** so they can focus their response.
- **Do not** recommend accepting a paper because it was the best in your set; **do not** recommend rejecting because it falls under some assumed quota — there is **no set quota**. The job is not to "find the best paper(s)" but to find all submissions worthy of archiving and sharing for the community.

### Expertise

In addition to a score, reviewers self-declare expertise:

| Code | Meaning |
|---|---|
| X | I am an expert on this topic (know related work well) |
| Y | I am knowledgeable on this topic |
| Z | I am an informed outsider |

- X/Y/Z denotes **expertise**, not confidence in judgement. If you lack confidence, state this in a comment to co-reviewers, listing reasons.
- Expertise is **not sent out to authors**.
- Not all reviewers need to be experts — non-expert reviews evaluate the paper's accessibility to a general audience.
- If all reviewers are non-experts, the chances of finding a champion are low — area chairs and PC chairs may assign extra reviewers.
- For interdisciplinary research, it is common to have reviewers who do not cover all disciplines — discuss with co-reviewers and let chairs know if additional expertise is needed.

### Plagiarism handling

If after reading a submission you suspect plagiarism:

- Read the ACM guidelines on Plagiarism, Misrepresentation, and Falsification
- Write the PC chairs to escalate the potential violation; share any information you have
- The chairs investigate and decide as necessary prior to the acceptance-notification deadline

---

# Part VIII — IDS deliverables (course schedule)

The course is structured around six deliverables (D1 to D6) submitted on Webcampus, in groups of three, in English. They cumulatively form the **registered report** that constitutes the final evaluation.

## D1 — Group and topic

- **Choice of context:** among those proposed on Webcampus, or propose your own
- Each context comprises several **topics of interest** — **one unique topic per group**
- Group registration on Webcampus (groups of 3) — https://webcampus.unamur.be/mod/choicegroup/view.php?id=172849
- Template available on Webcampus — https://webcampus.unamur.be/mod/assign/view.php?id=172847
- Announce the chosen context + topic on Teams

## D2 — Bibliography

- A list of articles
- **30 peer-reviewed published research articles**
- **No preprints** (e.g., from arXiv)
- In case of doubt, ask the lecturers
- Information and LaTeX template available on Webcampus
- Must report the **search engine** used and the **full and final search string**

## D3 — Context and research question

### Structure

- **Context and objectives** — similar to what is found in a structured abstract
- **One or two research question(s)**
- For each research question:
  - **Sub-questions or hypotheses**
  - A first general description of how the question will be addressed
- **Validate** your research questions

## D4 — Research-method poster

- Choose a research method from those available
- Present the **general characteristics** of the method
- Choose an **Exemplar** (concrete example paper using the method)
- Briefly present the topic and (especially) the **experimental protocol** developed

### Practical considerations

- Prefer a method capable of answering the research question described in D3
- **Two groups cannot choose the same Exemplar:** announce method + Exemplar on the Teams General channel as a reply to a designated message; first-come, first-served
- Respect the template format; submit the poster in **PDF only**

## D6 — Peer review

### Aims

- A peer review aims principally at **improving the report** — if reviewers point out weaknesses, they must also suggest measures to address them
- Each group member evaluates the pre-registration report of **another group** — each group thus produces **3 reviews** in total

### Evaluation basis

- Based on the report and the **pre-submission checklist** provided by the authors
- Three aspects (adapted from ICSE criteria):
  - **Soundness**
  - **Verifiability and Transparency**
  - **Presentation**
- For each criterion of the pre-submission checklist, verify that it is satisfied or that deviations are reasonable (and justified) along the three aspects
- If a criterion is not or only partially satisfied, **explain why** and **suggest possible improvements**

### Conduct rules

- **Focus on the report** — write "the report should also present […]" not "the authors should also present […]"
- Stay **polite, courteous, constructive** — the goal is to help authors improve their pre-registration report on the basis of the comments
- Treat the information **confidentially** — in a single-blind process, reviewers can see who they are and the totality of evaluations; they must not disseminate this information

---

# Part IX — Cross-cutting principles and unified flow

## The end-to-end research workflow as taught in IDS

| Stage | Question answered | Deliverable / artifact |
|---|---|---|
| 1. Pick context and topic | What domain do I study? | D1 |
| 2. Bibliographic search | What is already known? | D2 — list of 30 peer-reviewed papers, search string, snowballing |
| 3. State-of-the-art write-up | Where is the gap? | Background + Related Work sections |
| 4. Formulate research question | What do I want to find out? | D3 — RQs, sub-RQs, hypotheses, FINER + PICOT-checked |
| 5. Choose research method | How will I answer it? | D4 — research-method poster, Exemplar, threats to validity |
| 6. Empirical execution | What is the answer? | Data collection, analysis, statistical tests |
| 7. Reporting | How do I share this? | Pre-registration report → conference / journal paper |
| 8. Peer review | Is it sound, significant, novel, verifiable, well presented? | D6 — three peer reviews per group |

## Recurring principles

- **Demarcation drives:** state-of-the-art drives RQs; RQs drive protocols; results feed the state-of-the-art
- **Confidence vs threats:** every method choice trades against threats to validity (external, internal, construct, conclusion)
- **Replicability is non-negotiable:** repeatable, unambiguous experiments; sharing tools and data; positivist studies require recoverable methodologies, interpretivist work requires transparent qualitative procedures
- **Originality is incremental:** discoveries accumulate over many papers; replication studies are valued
- **Human dimension of science:** publish-or-perish economics shapes behavior; DORA and CoARA push reform; reviewing is unpaid labor at scale (~14 reviews/PC member at ICSE 2024)
- **Plagiarism is a hard line:** at university level (REE Article 81 → 0/20 or escalation) and at conference level (escalation to PC chairs)
- **Tooling tips:** use LaTeX + BibTeX; include a DOI when possible; cross-check Google Scholar with Scopus and DBLP; use https://www.connectedpapers.com/ and citation graphs to find seminal works
- **Quality gates for venues:** check journals against https://beallslist.net; verify editorial boards / conference organisers; the "Cyllage City COVID-19 / Zubat" paper is the canonical cautionary tale

## Key references cited across the course

- Hengl, T., Gould, M. (2006). *The unofficial guide for authors (or how to produce research articles worth citing)*. EUR 22191 EN. ISBN 92-79-01703-9. https://op.europa.eu/s/uZYT
- Arcuri, A., Briand, L. (2014). *A Hitchhiker's guide to statistical tests for assessing randomized algorithms in software engineering*. STVR 24(3): 219–250. DOI 10.1002/stvr.1486
- Saunders, M., Bristow, A., Thornhill, A., Lewis, P. (2019). *Understanding research philosophy and approaches to theory development*, in *Research Methods for Business Students* (8th ed.), Pearson Education, pp. 128–171
- Panichella, A., Kifetew, F.M., Tonella, P. (2018). *Automated Test Case Generation as a Many-Objective Optimisation Problem with Dynamic Selection of the Targets*. IEEE TSE 44(2): 122–158. DOI 10.1109/TSE.2017.2663435
- Panichella, A., Kifetew, F.M., Tonella, P. (2017). *LIPS vs MOSA: A replicated empirical study on automated test case generation*. SSBSE 2017: 83–98. DOI 10.1007/978-3-319-66299-2_6
- Kifetew, F., Devroey, X., Rueda, U. (2019). *Java Unit Testing Tool Competition — Seventh Round*. SBST 2019: 15–20. DOI 10.1109/SBST.2019.00014
- DORA — https://sfdora.org/read/
- CoARA — https://www.coara.org and https://www.unamur.be/fr/recherche/euraxess/coara
- ACM Empirical Standards — https://acmsigsoft.github.io/EmpiricalStandards/docs/
- ICSE 2022 Review Process and Guidelines — https://conf.researchr.org/getImage/icse-2022/orig/ICSE+2022+Review+Process+and+Guidelines-2.pdf
- MIT Citing guide — https://libguides.mit.edu/citing
- Scribbr Research Questions — https://www.scribbr.com/research-process/research-questions/
- PICOT — https://onlinenursing.duq.edu/blog/formulating-a-picot-question/
- Beall's List of predatory journals — https://beallslist.net
- Mining Software Repositories conference — https://conf.researchr.org/series/msr
