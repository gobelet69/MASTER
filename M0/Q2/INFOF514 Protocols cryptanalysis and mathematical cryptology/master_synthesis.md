# Master Synthesis — INFO-F514: Protocols, Cryptanalysis and Mathematical Cryptology

A unified knowledge architecture covering modern cryptology, cryptanalysis, e-voting protocols, provable security, homomorphic encryption, zero-knowledge proofs, post-quantum cryptography, side-channel and fault-injection attacks, and machine-learning model extraction. Lecturers: **Liran Lerman** and **Christophe Petit** (Université libre de Bruxelles), with invited lectures (Kostas Papagiannopoulos for fault/timing attacks, Stjepan Picek for ML security).

---

# 1. Foundations, Course Scope and Security Models

## 1.1 Course Overview and Goals

- **Course aim**: study modern cryptology and cryptanalysis tools — design, analysis, and implementation of cryptographic primitives and protocols, with critical analysis of current issues, focusing on **e-voting**.
- **Two parts**:
    - Part 1 (theoretical, Christophe Petit): provable security, homomorphic encryption, ZK proofs, cryptanalysis, post-quantum crypto.
    - Part 2 (applied, Liran Lerman with invited speakers): differential fault analysis, security of AI, security/crypto in industry, threat modeling, secure software implementation.
- **Prerequisite**: INFO-F415 Introduction to Cryptography.
- **Evaluation**: oral exam — 50% lecture content, 50% group project.
- **Project workflow**: form group of ~5 students; identify a research paper; submit one-page proposal (deadline 27/02/2026); progress report (27/03); group report ≤ 10 pages (30/04); individual report ≤ 4 pages (08/05); oral examination (June). Indicative mark grid: 70–100 Excellent; 60–69 Good; 50–59 Adequate; <50 Fail.
- **Lecture cadence (tentative)**:

| Week | Topic | Lecturer |
|---|---|---|
| 1 | Introduction & e-voting | CP & LL |
| 2 | Provable security | CP |
| 3 | Homomorphic encryption | CP |
| 4 | Zero-knowledge proofs | CP |
| 5 | Cryptanalysis | CP |
| 6 | Post-quantum cryptography | CP |
| 7 | Differential fault analysis | LL (Papagiannopoulos) |
| 8 | Security of AI | LL (Picek) |
| 9–10 | Security/Crypto in industry | LL |
| 11 | Threat modeling | LL |
| 12 | Secure software implementation | LL |

## 1.2 General Security Models

- **Black-box scenario**: attacker only sees inputs/outputs (plaintext, ciphertext); analyzed by classical cryptanalysis (linear, differential).
- **Grey-box scenario**: attacker additionally observes side-channels (timing, power, EM emanations) — unintentional leakage giving a “blurry view” of internal computations.
- **White-box model**: attacker has full access to implementation and intermediate states.
- **Threat-modeling frameworks (Shostack)**:
    - **STRIDE** (security): Spoofing, Tampering, Repudiation, Information disclosure, Denial of service, Elevation of privilege.
    - **LINDDUN** (privacy): Linkability, Identifiability, Non-repudiation, Detectability, Disclosure of information, Unawareness, Non-compliance.
- **Sensitive assets in e-voting**: vote confidentiality, election integrity, voter identity, decryption keys, randomness sources, bulletin board content.
- **Industrial reference**: Skorobogatov, “How microprobing can attack encrypted memory” — physical probing recovers data even from encrypted memory; software countermeasures alone are insufficient.

---

# 2. Voting Systems & E-Voting

## 2.1 Motivation and Real-World Context

- Voting is central to democracy: local, regional, national and European elections; union and organizational decisions; ULB rectoral elections (2025) used cryptographic systems with student/staff participation.
- **Direct Recording Electronic (DRE) machines**: used in USA since 1974 (also Brazil, India, Australia, Canada, DR Congo); typically general-purpose computers running secret election software with a UI; **no cryptography**.
- **DRE security record**:
    - Common software vulnerabilities; insecure update mechanisms; hardcoded crypto keys; malware able to read, modify and propagate votes.
    - Code leaked on public FTP servers; weak physical locks; discarded machines still containing votes.
- **Backlash**: criticism after 2000 US presidential election (Gore vs Bush). 2009 German Federal Constitutional Court ruling: “verification of the result must be possible by the citizen reliably and without any specialist knowledge”. The Netherlands abandoned e-voting; still used in Brazil, India, DR Congo.

## 2.2 Security Goals for Voting

- **Correctness**:
    - Result consistent with intended votes.
    - **Verifiability**: the system itself provides correctness guarantees.
- **Privacy**:
    - **Confidentiality** of individual votes.
    - **Coercion resistance**: voter cannot prove how they voted (limits vote-buying).
- **Fundamental tension**: verifiability vs privacy — how to certify results without seeing the votes? Plus careless/malicious users, malicious software/hardware, trapdoored randomness.
- **End-to-end (E2E) verifiability**: voter can verify
    - **Cast as intended** (their vote was encrypted correctly).
    - **Recorded as cast** (their ciphertext appears on the bulletin board).
    - **Counted as recorded** (the tally correctly aggregates the bulletin board).

## 2.3 Naive Attempts and Iterative Improvements

- **Attempt 1 — Plain encryption**: officials generate keys; voters encrypt and submit; officials decrypt and tally.
    - Issues: officials see all votes; can add/change/remove votes.
- **Attempt 2 — Encrypted bulletin board**: publish all encrypted votes.
    - Voters check their vote is on board; tallying is witnessed; signatures enable integrity checks.
    - Remaining issues: officials/witnesses can know all votes; voters can prove how they voted (by retaining randomness).
- **Two main cryptographic families**:
    - **Homomorphic encryption** approach: sum encrypted votes; only the result is decrypted.
    - **Mixnet** approach: shuffle ciphertexts to break the link voter → vote, then decrypt individually.

## 2.4 Required Cryptographic Tools

- **Homomorphic encryption** to aggregate votes and re-randomize ciphertexts (ElGamal is homomorphic).
- **Zero-knowledge proofs** to prove vote well-formedness, correct aggregation, correct decryption, correct shuffle.
- **Secret sharing / threshold encryption** so that no single trustee can decrypt.

## 2.5 Homomorphic-Encryption-Based E-Voting

### 2.5.1 ElGamal and Exponential ElGamal (used)

- See Section 4 for details. Key facts used in voting:
    - Encryption of `m`: `(c1, c2) = (g^r, m·h^r)`; secret key `s` with `h = g^s`.
    - **Exponential ElGamal**: encrypt `m` as `(g^r, g^m·h^r)` with bound `B`; decryption requires solving DLP over a small interval.
    - **Homomorphic addition** for exponential ElGamal: `(c1·c1', c2·c2') = (g^(r+r'), g^(m+m')·h^(r+r'))`.
    - **Re-randomization**: multiply by an encryption of `0` (additively) or `1` (multiplicatively) without knowing the plaintext.

### 2.5.2 Threshold ElGamal (Pedersen 1991)

- **Goal**: split decryption among trustees so that any `t` out of `n` can decrypt, none alone can.
- **Setup**: each trustee `i` has share `s_i = F(i)` for a polynomial `F` of degree `k-1`; secret key is `F(0)`; public key `h = g^F(0)`.
- **Encryption** as in ElGamal: `(c1, c2) = (g^r, m·h^r)`.
- **Lagrange interpolation**: for any subset `{x_1, ..., x_t} ⊆ {1, ..., n}`,

        F(0) = Σ_i L_i F(x_i),    L_i = ∏_{j ≠ i} (-x_j / (x_i - x_j))

- **Public key reconstruction**: `∏_i (g^F(x_i))^L_i = g^F(0)`.
- **Decryption**: `c2 / ∏_i c1^{F(x_i)·L_i} = c2 / c1^F(0) = m`.
- **Pedersen distributed key generation**: each party picks a random polynomial `F_i(x)`, sends `F_i(j)` privately to party `j`; `F = Σ F_i`. `F(0)` is unknown to anyone if at least one trustee is honest.

### 2.5.3 Vote Well-Formedness via OR-Proof

- Voters must prove their ciphertext encrypts `m ∈ {0, 1}` (not `1000` or `-1`).
- A vote `(c1, c2) = (g^r, g^m·h^r)` is well-formed iff one of `(g, h, c1, c2)` or `(g, h, c1, c2/g)` is a Diffie-Hellman tuple.
- **Construction**: combine Chaum-Pedersen and OR-proof.
    - Real Chaum-Pedersen proof using witness `r` for the true case.
    - Simulated Chaum-Pedersen proof for the false case.
- **Non-interactive version** via Fiat-Shamir: hash all commitments to get the challenge, split as `β = β_0 ⊕ β_1`.

### 2.5.4 Correct Decryption Proof

- **Non-threshold variant**: trustee `i` reveals `c1^{x_i}` and proves `(g, g^{x_i}, c1, c1^{x_i})` is a DH tuple via Chaum-Pedersen. Verify `c2 / ∏ c1^{x_i} = c2 / c1^x = m`.
- **Threshold variant** uses Lagrange-weighted combination: `c2 / ∏_{i ∈ I} c1^{F(i) L_i} = c2 / c1^{F(0)} = m`.
- All proofs are made non-interactive with Fiat-Shamir.

## 2.6 Mixnet-Based E-Voting

- **Idea**: shuffle ciphertexts before decryption so votes can no longer be linked to voters; then decrypt individually.
- **Naive single-trustee**: trustee re-randomizes and shuffles. Issues: trustee may add/remove votes; trustee + decryptor can collude.
- **Multi-trustee mixnet** (Wikipedia-style picture in lectures):
    - Each vote is encrypted multiple times (one layer per trustee).
    - Each trustee removes one encryption layer and shuffles all votes.
    - Each shuffle is accompanied by a ZK proof of correctness.
- **ElGamal with shared secret optimization**: each trustee `i` has `s_i`, public key `h = ∏ h_i = g^{Σ s_i}`. Single encryption layer, multiple decryption layers — but the `c1` part is common across layers and can be tracked back unless re-randomized.
- **Fix**: each trustee both partially-decrypts and re-randomizes:

        (c1, c2) → (c1, c2/c1^{s_i}) → (c1·g^r, (c2/c1^{s_i})·h_i^r)

  where `h_i = ∏_{j=i+1}^N g^{s_j}`.

- **Required ZK proofs** per trustee:
    - Decryption is correctly performed.
    - Shuffle is correctly performed.
- **Sako-Killian shuffle proof**: produce a third equivalent set `V_3`; receive challenge bit; reveal permutation/randomness either between `V_1, V_3` or between `V_2, V_3`; repeat with Fiat-Shamir.
- **Modern efficient shuffle proof**: Bayer-Groth (Eurocrypt 2012).

## 2.7 Helios — A Practical Case Study

### 2.7.1 Why Helios

- One of the first **open-source** end-to-end-verifiable e-voting implementations.
- First such tool used at large scale (~25,000 electors) for the **UCLouvain 2009 rector election**.
- Used by the **IACR** for its elections.
- Slogan: **Trust no one for integrity, trust Helios for privacy**.

### 2.7.2 Helios 1.0 (Adida, Usenix 2008)

- **Mixnet** approach with a single trustee (Helios server).
- ElGamal encryption.
- Hash of encryption returned to voter as a receipt.
- Bulletin board of all votes.
- Sako-Killian proofs for the mixnet shuffles.
- Chaum-Pedersen proofs for correct decryption.
- **Ballot auditing**: voters can choose to **audit** or **cast**:
    - Audit: voter receives the encryption randomness, can independently verify the ciphertext and ballot tracker.
    - Cast: randomness is discarded, voter authenticates and submits.
- “**Coerce me!**” button (educational): reveals ElGamal randomness so the voter can prove their vote — only suitable for low-coercion contexts.

### 2.7.3 Helios 2.0 (Adida, Pereira, de Marneffe — UCL 2009 rectoral election)

- **Weighted election** (staff vote weighted more than student vote, but only the global result revealed):
    - Exponential ElGamal; weighted result computed via homomorphic property:
    
            Enc(2v + v') = Enc(v) ⊗ Enc(v) ⊗ Enc(v')
    
    - Proof that the sum of votes is `1` (one vote per voter).
- Decryption key shared by a set of trustees (not threshold).
- Removed the “Coerce me!” button (confusing to voters).
- Same auditing capabilities.
- Still recommended only for low-coercion-threat elections.

### 2.7.4 Non-Cryptographic Attack on Helios 2.0

- Estehghari–Desmedt (USENIX 2010): every candidate could provide a URL pointing to their candidacy statement. A malicious candidate uploaded a crafted PDF; Adobe Acrobat Reader vulnerabilities allowed installing a malicious browser extension on voter machines, enabling social-engineering attacks that fool the voter into accepting a hacked ballot.
- Caused upgrade to Helios 3.0.

### 2.7.5 Belenios

- Successor to Helios that additionally provides **eligibility verifiability** (only authorized voters can have their ballots counted).

## 2.8 Coercion and Online Voting

- Private booths help against coercion in person; with home voting, a coercer can be present.
- **Mitigation**: allow voters to **change their vote multiple times** until the end of the voting period (Estonian system, later Helios versions). Coercer cannot be sure their vote will be the last.
- Helios 1.0/2.0 explicitly do not solve coercion; Helios is recommended only when coercion threat is low.

## 2.9 Other Cryptographic Voting Systems

- Scantegrity, Prêt-à-Voter, STARVote, D-DEMOS — paper ballots, receipts in many forms (punch cards, bar codes, QR codes, scratch cards), more or less complex protocols, sometimes with interactive proofs.

## 2.10 General Practical Challenges

- Humans are bad at using crypto protocols:
    - Elections are too rare for routine.
    - Voters cannot compute on their own and rely on external code.
    - In interactive proofs, a swap of two messages may go unnoticed (allowing a simulated proof).
    - Few voters follow audit procedures.
- Randomness elements may be **trapdoored**.
- See Halderman, “Practical attacks on real-world e-voting”.

---

# 3. Provable Security

## 3.1 Reductionist Approach

- **Why proofs?** Cannot test all attacks experimentally; must precisely define **secure** and reduce to a hard problem.
- **Three steps**:
    1. **Define what it means to break the protocol**: adversary’s goal, resources, access to the system.
    2. **Choose a hard computational problem**: cannot be solved even by clever people with the best computers.
    3. **Prove**: Breaking the protocol ⇒ Solving the hard problem.
- Reductions chain: attack on a security protocol (TLS, SSH, Signal, e-voting) ⇒ attack on a building block (RSA signatures, DH key exchange) ⇒ algorithm for a hard problem (factoring, DLP).

## 3.2 The Meaning of “Hard”

- **Asymptotic hardness**: no polynomial-time adversary solves a given instance with non-negligible probability.
    - Security parameter `λ ~ problem size`. Adversary is an algorithm with complexity `f(λ)`.
    - **Negligible** = smaller than `1/p(λ)` for every polynomial `p`.
- **Concrete hardness**: cannot solve today with the best computers (e.g., success probability `≤ 2^{-50}` in time `≤ 2^{80}` seconds and `≤ 2^{40}` GB).
- **Public-key specifics**: hardness drawn from number theory and other math; suited to asymptotic statements; concrete hardness evaluated via long research history, challenges, benchmarks.

## 3.3 Catalogue of Hard Problems

- **Integer factorization**: Given `n = pq` with `p, q` well-chosen primes, best classical complexity

        L_n(1/3, (64/9)^{1/3}) = exp((c + o(1))(log n)^{1/3} (log log n)^{2/3})

  Largest RSA challenge solved: **829 bits**.
- **Discrete logarithm in F_p^***: Given `g` a generator and `g^x mod p`, find `x`. Easy direction via square-and-multiply:

        1: write x = Σ x_i 2^i
        2: a' ← a; c ← a^{x_0}
        3: for i = 1 to n: a' ← a'^2 mod p; if x_i = 1 then c ← c·a'
        4: return c

  Best algorithm: same `L_p(1/3, (64/9)^{1/3})` complexity. Current record: **795 bits (Dec 2019)**. Diffie-Hellman’s original paper suggested 200-bit primes — far too small today.
- **Generalizations**: any finite cyclic group. In cryptography:
    - Multiplicative groups of finite fields: `F_p`, `F_{p^n}` (pairings), `F_{2^n}` now to be avoided (quasi-polynomial DLP since 2013).
    - Elliptic and hyperelliptic curve subgroups: complexity `O(|G|^{1/2})` for well-chosen curves.
- **Solving polynomial systems** over finite fields: NP-hard in general; basis of multivariate cryptosystems (still under scrutiny). Many parameters complicate evaluation.
- **Lattice problems**: SVP (find shortest vector), CVP (find closest vector to a point). Active research; many parameters; basis of post-quantum schemes.

## 3.4 Choosing a Hard Problem

- Must be **really** hard (not just for you, after 30 minutes).
- Ideally with research history.
- Must enable many efficient cool protocols (small keys, fast operations).

## 3.5 Security Notions for Public-Key Encryption

- **Public-Key Encryption Scheme** = (KeyGen, Enc, Dec):
    - **KeyGen(λ)** → `(SK, PK)`.
    - **Enc(PK, m)** → `c`.
    - **Dec(SK, c)** → `m`.
- All three may be probabilistic; algorithms must abort or return random plaintext on bad inputs.
- **Correctness**:

        Pr[m' = m : (PK,SK) ← KeyGen(λ); c ← Enc(PK,m); m' ← Dec(SK,c)] ≈ 1

  Perfect correctness if probability exactly 1.
- **IND-CPA (indistinguishability under chosen-plaintext attack)** game:
    - Challenger generates `(PK, SK)`, sends `PK`.
    - Adversary picks `m_0, m_1`.
    - Challenger picks random bit `b`, sends `c = Enc(PK, m_b)`.
    - Adversary outputs guess `b'`. Wins iff `b' = b`.
    - Scheme is IND-CPA secure if `|Pr[win] - 1/2| ≈ 0`.
- **Deterministic encryption ⇒ not IND-CPA**: adversary recomputes `Enc(PK, m_i)` and compares. Textbook RSA is deterministic; RSA-OAEP adds randomness.
- **IND-CCA(2) (chosen-ciphertext)**: adversary additionally has access to a decryption oracle; in the adaptive (CCA2) version, oracle calls are also allowed after receiving `c`, except on `c` itself.
- **Why CCA matters**: Bleichenbacher (Crypto’98) — protocols may leak partial information through their behavior, sufficient to mount CCA-style attacks.
- **Hierarchy**: IND-CCA2 ⇒ IND-CCA ⇒ IND-CPA. Converse fails in general; CCA(2) schemes are usually built from CPA + hash functions (e.g., Fujisaki-Okamoto).

## 3.6 Diffie-Hellman / DLP-Related Problems

- For `G` cyclic of prime order `q` with generator `g`:
    - **DLP**: given `h`, find `x` with `h = g^x`.
    - **CDH (computational DH)**: given `g^a, g^b`, compute `g^{ab}`.
    - **DDH (decisional DH)**: distinguish `(g, g^a, g^b, g^{ab})` from `(g, g^a, g^b, g^c)` random.
- **Reductions**: DLP solver ⇒ CDH solver ⇒ DDH solver. Converses unknown; DLP and CDH often equivalent in practice. Some groups have easy DDH but hard CDH (pairing-friendly elliptic curves).
- **DLP vs CDH (Maurer)**: with some precomputation, a CDH oracle can solve DLP. Build `g^{x^2}` from `CDH(g^x, g^x)`, square-and-multiply in the exponent to compute `g^{x^e}`, then if `|G| - 1` is smooth use Pohlig-Hellman in the exponent. In general, find a smooth-order elliptic curve modulo `|G| - 1`, with `x` the x-coordinate of a point.
- **Static Diffie-Hellman oracle**: given `g^x`, returns `g^{ax}` for fixed `a`. Built from an ElGamal decryption oracle: send `(g^x, c_2)`, get `m = c_2 / g^{ax}`, deduce `g^{ax} = c_2/m`. Brown-Gallant: if `|G| - 1 = uv`, can solve DLP in time `u + √v` with `u` SDH-oracle calls; for `v ≈ u^2` this gives `O(|G|^{1/3})` — beats generic algorithms.

## 3.7 Diffie-Hellman Key Agreement

- Choose `g` generating `G`. Alice picks `a`, sends `g^a`; Bob picks `b`, sends `g^b`. Both compute `g^{ab}`. Eve cannot recover `a, b, g^{ab}` (DLP/DH problems).

## 3.8 ElGamal Encryption

- **KeyGen**: cyclic group `G` of prime order `q`; `x ∈ [1, q]`; generator `g`; `h = g^x`. Private `x`, public `(G, g, h)`.
- **Enc(m)**: random `r`; `c = (c_1, c_2) = (m·h^r, g^r)`.
- **Dec(c)**: `m' = c_1·c_2^{-x}`.
- **Security**:
    - Perfectly correct.
    - Recovering `x` from `(g, h)` ⇔ DLP.
    - Decryption ⇔ CDH (build CDH instance with `c_1 = 1, c_2 = g^b`, so `Dec = g^{-ab}`).
    - **DDH hard ⇒ ElGamal IND-CPA**:
        - Reduction simulates IND-CPA for the adversary using `(g, g^a, g^b, g^c)`. If `c = ab`, simulation is real; else `c` is independent of `b`, adversary wins with exactly 1/2. Combined: DDH solver succeeds with advantage `ε/2`.
    - **Not IND-CCA**: Given `(c_1, c_2) = (m_b·h^r, g^r)`, query oracle on `(c_1·h, c_2·g)` to obtain `m_b` directly. Use **Cramer-Shoup** for CCA security.

## 3.9 Limits of Provable Security

- A “provably secure” protocol can still be broken if:
    - The proof is wrong (many examples in top-tier publications; see Koblitz–Menezes “Critical perspectives on provable security”).
    - The “hard problem” is not actually hard.
    - The security model fails to capture reality.

### 3.9.1 Subgroup Attacks

- **Naive DH implementation**:

        p = random_prime(2**1024); g = 2; a = random_integer(2**1024); h = pow(g, a, p)

  is **not safe**.
- **Pohlig-Hellman**: if `g` has order `N | p-1` and `q | N` is small, then `(g^{N/q})^a = h^{N/q}` gives `a mod q`. Use CRT across all small factors → if `N` is smooth, DLP is easy.
- **Random primes are not safe primes**: factors of `p-1` typically include small primes. **Safe prime** = `p` such that `(p-1)/2` is prime.
- **Small subgroup attacks (DSA-style)**: choose `p` with prime factor `q` of 160 bits, `g` of order `q`. If Bob doesn’t check `g`’s order, attacker sends `g_i` of small order `p_i | N`, gets `g_i^b`, recovers `b mod p_i`, combines via CRT. **Countermeasure**: always verify `g`’s order.

### 3.9.2 Weak Randomness

- **RSA shared primes (Lenstra et al., “Ron was wrong, Whit is right”)**: if two RSA keys `n_a = pq_a, n_b = pq_b` share `p`, then `gcd(n_a, n_b) = p`. Demonstrated in practice: ~2/1000 RSA keys vulnerable.
- **RSA with small private key `d`**: `de = kφ(N)+1 = k(N-z)+1` with `z = O(√N)`, `d, k` small. Coppersmith’s lattice methods solve the resulting small-root problem.
- **ECDSA**:
    - Setup: hash `H`, field `K`, prime `q`, curve `E` with `qh` points (`h ≤ 4`), point `P` of order `q`, secret `x`, public `Q = xP`.
    - Sign: random `k`, `T = kP`, `r = f(T)`, `e = H(m)`, `s = (e + xr)/k mod q`. Output `(r, s)`.
    - Verify: `u_1 = e/s`, `u_2 = r/s`; `T = u_1 P + u_2 Q`; accept iff `r = f(T)`.
    - **Repeated `k`**: two signatures `(r, s)` and `(r, s')` give

            x = (s e' - s' e) / (r (s' - s)) mod q

      (used to recover Sony PS3 secret key).
    - Bias in `k` → lattice attacks (Howgrave-Graham, Smart). Android RNG weakness led to 56 BTC theft in 2013.
- **Dual EC-PRNG**: NIST-standardized PRNG; parameters can be backdoored. Other variants in the same standard had no proof but no backdoor; evidence NSA pushed Dual EC, knew the backdoor and used it.

### 3.9.3 Strong (Physical) Adversaries

- **Side-channel attacks** (passive observation):
    - **Square-and-Multiply leakage**: operation sequence depends on the secret bits. Power trace reveals bits (with averaging to reduce noise).
    - **Countermeasures**: always-multiply-and-mask register update; randomize exponent `x → x + r·(p-1)`.
    - **Hamming-weight model**: power proportional to number of `1`s in a register.
    - **Hamming-distance model**: power proportional to number of bit-flips.
    - **Asymmetric model**: `1 → 0` and `0 → 1` flips leak differently.
    - Channels: power, timing, EM, sound, cache. See Standaert, “Introduction to side-channel attacks”.
- **Fault attacks** (active modification of computation):
    - Inject by varying voltage/clock/temperature, laser, X-ray, ion beam.
    - Realistic effects: set register to 0 / random / arbitrary value.
    - **Bellcore RSA-CRT attack**: decryption computes `m_p = c^d mod p`, `m_q = c^d mod q`, recombines via CRT. Inject fault so `m_p' = c^d mod p'`. Then `gcd(m - m', n) = q`.
- **Cold boot attack**: remove power while key in memory; cooler memory keeps data longer.
- **Microarchitectural attacks (Meltdown, Spectre)**: bypass HW isolation between processes, leaking cryptographic keys; see meltdownattack.com.
- **Quantum computers**: solve DLP and factoring in polynomial time; break SSH, TLS, Signal, PGP. Lattice problems, polynomial systems, word problems are not known to be broken; NP-hard problems’ status quantum-wise also unknown.

## 3.10 Bottom Line

- Security proofs have considerable value: rule out structural weaknesses, focus cryptanalysis, inspire design.
- A “provably secure” protocol can still be very insecure (wrong proof / wrong hardness assumption / wrong model). Some authors argue we should call them **security arguments** rather than proofs.

---

# 4. Homomorphic Encryption

## 4.1 Definition

- An encryption scheme is **homomorphic** w.r.t. plaintext operation `⊕` and ciphertext operation `⊗` if

        Enc(m_1 ⊕ m_2) = Enc(m_1) ⊗ Enc(m_2)

- **Additively** (resp. **multiplicatively**) homomorphic if `⊕` is `+` (resp. `·`), typically over a finite structure.
- **Fully homomorphic encryption (FHE)**: scheme is homomorphic w.r.t. a complete set of operations (addition + multiplication suffices to evaluate arbitrary circuits).
- **Somewhat homomorphic encryption (SHE)**: supports both additions and multiplications, but only a bounded number.
- **Reminder — IND-CPA / CCA(2)**: see Section 3.5.
- **Homomorphic ⇒ not IND-CCA2**: adversary computes `c_b' = c_b ⊗ Enc(0)` (additive case); since `c_b' ≠ c_b`, oracle decrypts it and returns `m_b`. Thus homomorphic encryption breaks CCA2 by construction.

## 4.2 Multiplicatively Homomorphic Cryptosystems

### 4.2.1 RSA

- **Setup**: `p, q` strong primes; `n = pq`; `e ∈ [1, φ(n)]` with `gcd(e, φ(n)) = 1`; `d = e^{-1} mod φ(n)`. Private `(p, q, d)`, public `(n, e)`.
- **Enc**: `c = m^e mod n`; **Dec**: `m' = c^d mod n`.
- **Euler**: `x^{φ(n)} = 1 mod n` for `x ∈ Z_n^*`.
- **Security**: recovering `(p, q)` from `n` ⇔ factoring; decrypting ⇔ RSA problem (e-th roots mod `n`). Textbook RSA is deterministic ⇒ not IND-CPA / CCA / CCA2; RSA-OAEP fixes this.
- **Multiplicative homomorphism**: `c_1·c_2 = (m_1 m_2)^e mod n` ⇒ encryption of `m_1 m_2`. Useful for some applications (this is in fact a reason **not** to use textbook RSA in general).

### 4.2.2 ElGamal (Multiplicative)

- See Section 3.8.
- **Homomorphism**: `(c_1·c_1', c_2·c_2') = (g^{r+r'}, m m'·h^{r+r'})` ⇒ encryption of `m m'`. With `m' = 1`, gives a **re-randomization** procedure.
- Use Cramer-Shoup variant for IND-CCA security (loses the homomorphism).

## 4.3 Additively Homomorphic Cryptosystems

### 4.3.1 Exponential ElGamal

- See Section 2.5.1.
- Homomorphism: `(c_1·c_1', c_2·c_2') = (g^{r+r'}, g^{m+m'}·h^{r+r'})` ⇒ encryption of `m + m'`.
- DLP over a small interval recoverable via exhaustive search or Baby-Step-Giant-Step.

### 4.3.2 Paillier Cryptosystem

- **Setup**: `p, q` large primes, `n = pq`; group `Z_{n^2}^*`. nth roots of unity given by `x_k = (1+n)^k = 1 + kn mod n^2`. Define `L : x_k → k = (x_k - 1)/n`. DLP is easy in this subgroup: `L(x_k^m) = km = m·L(x_k)`.
- `λ = lcm(p-1, q-1)`. For any `g ∈ Z_{n^2}^*`, `g^λ` is an nth root of unity. Choose random `g` with order divisible by `n`; let `μ = (L(g^λ mod n^2))^{-1} mod n`.
- **Public** `(n, g)`, **secret** `(λ, μ)`.
- **Encryption**: `0 ≤ m < n`, random `r ∈ Z_n^*`, `c = g^m·r^n mod n^2`.
- **Decryption**: `m = μ·L(c^λ mod n^2) mod n`.
- **Correctness sketch**: `c^λ = g^{mλ}·r^{λn}`. Since `r^{λn} = 1`, `c^λ = g^{mλ} = (1+kn)^m = 1 + kmn mod n^2`; so `L(c^λ) = km`; and `μ·km = m·L(g^λ)·μ = m`.
- **IND-CPA security**: composite residuosity assumption — given `z ∈ Z_{n^2}^*`, hard to decide whether `∃ y` with `z = y^n mod n^2`.
- **Additive homomorphism**: `Enc(m_1)·Enc(m_2) = g^{m_1 + m_2}·(r_1 r_2)^n = Enc(m_1 + m_2)`.

## 4.4 Application to E-Voting

- See Section 2.

## 4.5 Somewhat Fully Homomorphic Encryption

### 4.5.1 Pairing-Based: Boneh-Goh-Nissim

- **Setup**: `n = pq` (RSA-style), `r = 4nℓ - 1` prime for small `ℓ`. Curve `y^2 = x^3 + x` over `F_r` is supersingular with `#E(F_r) = r + 1 = 4nℓ`. Take `P` of order `n`, group `G_1 = ⟨P⟩`, `G_3 = F_r^*`. Symmetric pairing `e : G_1 × G_1 → G_3`. Pick `Q' ∈ G_1`, `Q = q·Q'` of order `p`. Secret `q`, public `(n, P, Q)`.
- **Encryption** of `m`: random `t`; `C = m·P + t·Q`.
- **Decryption**: compute `pC = m·pP` (since `pQ = pq·Q'` has order `p` ⇒ `p·Q = O` because `P` has order `n` and `pn` is the curve order — actually `pQ = pqQ' = (n·Q'/something)`; concretely, `pC = m·pP + t·pq·Q' = m·pP`). Solve DLP of `pC` w.r.t. `pP` (feasible if `m` is small).
- **Pairing reminders**:
    - Bilinear: `e(P_1 + Q_1, P_2) = e(P_1, P_2)·e(Q_1, P_2)`; `e(P_1, P_2 + Q_2) = e(P_1, P_2)·e(P_1, Q_2)`.
    - Non-degenerate: `∀ P_1 ≠ O, ∃ P_2` with `e(P_1, P_2) ≠ 1`.
    - `e(jP, Q) = e(P, Q)^j = e(P, jQ)`. `e(P, O) = 1`. Symmetric pairing if `G_1 = G_2`.
- **Homomorphic addition**: `C_1 + C_2 = (m_1 + m_2)·P + (t_1 + t_2)·Q`.
- **Homomorphic “multiplication”** via pairing:

        e(C_1, C_2) = e(P,P)^{m_1 m_2}·e(P,Q')^{(m_1 t_2 + m_2 t_1)q}·e(Q',Q')^{t_1 t_2 q^2}

  After raising to `p`: `e(C_1, C_2)^p = e(P, P)^{p m_1 m_2}` (other terms vanish since `pq Q' = O`). Decrypt by DLP w.r.t. `e(P, P)^p`.
- **Capabilities**: arbitrary number of additions, then **one** multiplication, then arbitrary additions (i.e., any quadratic function of plaintexts).

### 4.5.2 Lattice-Based / Approximate-GCD Construction

- **Symmetric-key version**: secret `p` large prime; encrypt bit `m` as `c = m + 2r + pq`, with `r << p` and `q` large. Decrypt `m' = (c mod p) mod 2`.
- **Correctness**: `(m + 2r + pq) mod p = m + 2r` (as long as `m + 2r < p`); reducing mod 2 returns `m`.
- **Security**: approximate-GCD problem (recovering `p` from samples `pq_i + s_i`); reformulable as a lattice problem.
- **Additive homomorphism**: `Enc(m_1) + Enc(m_2) = (m_1 + m_2) + 2(r_1 + r_2) + p(q_1 + q_2)`. More generally `Enc(Σ m_i) = Σ m_i + 2 Σ r_i + p Σ q_i`. Decrypts correctly while `Σ m_i + 2 Σ r_i < p`.
- **Multiplicative homomorphism**: `Enc(m_1)·Enc(m_2) = m_1 m_2 + 2(m_1 r_2 + r_1 m_2 + 2 r_1 r_2) + p(...)`. Generalizes to `Enc(∏ m_i)`.
- **Noise growth**: every operation grows `r`; multiplications grow it much faster than additions; once `2R > p`, decryption fails.
- **Public-key version**: publish many encryptions of 0, `c_i = 2 r_i + p q_i`. Encryption: `c = m + Σ_{i ∈ I} c_i + 2r` for a random subset `I`. Decryption and homomorphic ops as before.
- **Variants**: most are based on lattice problems (Section 7); a few specific schemes have been broken, but those built on well-studied **Learning With Errors** remain solid.

## 4.6 Fully Homomorphic Encryption (Gentry 2009)

- **Long-standing open problem** until Gentry’s 2009 breakthrough; many follow-ups.
- **Key ideas**:
    - Use a SHE scheme (noise-bounded ciphertexts).
    - **Bootstrapping**: include in the public key an encrypted version of the SHE decryption key. To reduce noise of a ciphertext `c`, homomorphically evaluate `f_c(SK) = Dec(c, SK)` using the encrypted `SK`. The result is a fresh encryption of the same plaintext with **smaller noise**.
- **Bootstrapping bound**: SHE noise must remain small enough after evaluating `Dec` plus one extra multiplication. If so, iterate to evaluate any circuit.
- **Progress**:
    - Gentry’s first implementation: terabytes of keys, ~30s per homomorphic op.
    - 2nd, 3rd, 4th FHE generations: better ciphertext/plaintext ratios, slower noise growth, dedicated circuits (e.g., for ML).
    - **Implementations**: HELib, SEAL, etc.
    - Standardization: homomorphicencryption.org.

## 4.7 Take-aways

- Many textbook public-key schemes have additive or multiplicative homomorphic properties. These break IND-CCA, but enable e-voting and similar applications.
- SHE schemes allow more (one mul + many adds, or limited circuits).
- Gentry: SHE + bootstrapping = FHE.

---

# 5. Zero-Knowledge Proofs

## 5.1 What Is a “Proof”?

- A “valid proof” of knowing `x` such that `g^x = h mod p` could be: “here is `x`” — but then `x` is no longer secret.
- For Diffie-Hellman tuples `(g_1, g_2, g_3, g_4)` with `∃ x: g_2 = g_1^x ∧ g_4 = g_3^x`, revealing `x` would expose votes/keys in voting contexts.
- Even valid proofs of identity (UK ID cards) reveal way more information than needed.
- **Goal of a ZK proof**: prove a statement without revealing any extra information.

## 5.2 Mic Ali’s Cave (Quisquater–Guillou)

- Cave with two entries and a wall in the middle openable by a password.
- **Peggy** wants to prove to **Victor** that she knows the password without revealing it (and without enabling Victor to convince others).
- **Protocol**:
    - Peggy enters one side at random.
    - Victor (who hasn’t seen which) shouts a random side.
    - Peggy comes out on that side, using the password if needed.
    - Without password: 50% cheating success per round; `2^{-k}` after `k` rounds.
- **Properties**:
    - **Correctness**: an honest knowledgeable Peggy convinces Victor.
    - **Soundness**: a cheating Peggy fails except with negligible probability.
    - **Zero-knowledge**: the transcript can be **simulated** without the password (pick the exit side first, let Peggy enter that way).
    - **Non-transferability**: Victor cannot use the transcript to convince others (collusion cannot be ruled out from the outside).

## 5.3 Formal Definitions

- Statements: `L = {x ∈ X | ∃ w ∈ W, R(x, w) = 1}` for an NP relation `R` (poly-time evaluable).
- **Sigma protocol** (3 rounds):
    - Prover sends a **commitment** `α`.
    - Verifier sends a random **challenge** `β`.
    - Prover sends a **response** `γ`.
    - Verifier accepts iff `V(x, α, β, γ) = 1`.
- **Correctness (formal)**: honest prover always convinces verifier.
- **k-special soundness**: a PPT extractor produces a witness from `k` valid transcripts sharing the same commitment but with distinct challenges. If `k` such transcripts can be produced, the prover must know `w`.
- **Honest-Verifier Zero-Knowledge (HVZK)**: a PPT simulator produces transcripts indistinguishable from real ones, without using `w`. (The simulator may compute messages out of order; this does not contradict soundness because a real prover cannot do so against an adversarial verifier.)
- **Quality of properties**:
    - **Perfect** (always),
    - **Statistical** (overwhelming probability),
    - **Computational** (assuming a problem is hard).
- **Impossibility**: cannot have perfect soundness AND perfect zero-knowledge simultaneously.
- **ZK proof vs ZK argument**: an argument has only computational soundness.
- The Mic Ali protocol is sound and HVZK but **not** special-sound.
- **Identification protocol**: KeyGen returns `(x, w)`; the protocol proves knowledge of `w` matching public `x`. ZK ensures replays don’t leak info.

## 5.4 ZK for Graph Isomorphism

- Two graphs `G_0, G_1` with isomorphism `π : G_0 → G_1` known to Prover.
- **Protocol**:
    - Prover picks random permutation `σ_1 : G_1 → H`, sends `H` as commitment.
    - Verifier sends bit `b`.
    - Prover sends `σ_b : G_b → H` (`σ_0 = σ_1 ∘ π`).
    - Repeat `k` times.
- **Soundness**: 2-special — given valid responses for `b = 0` and `b = 1`, recover `π = σ_1^{-1} ∘ σ_0`.
- **HVZK**: simulator picks `b`, random `σ_b`, deduces `H`, returns `(H, b, σ_b)`.

## 5.5 ZK for 3-Coloring → Any NP Statement

- 3-coloring is NP-complete; reducing any NP statement to 3-coloring gives a ZK proof for **any NP statement** — Goldreich–Micali–Wigderson.
- **Protocol** (with one-way permutation `f`, e.g., encryption with secret key unknown to verifier):
    - Prover picks random color permutation `π`, lets `φ' = π ∘ φ`.
    - Prover commits to each vertex: `f(φ'(v) || r_v)` with `r_v` long random bitstrings (commitment is hiding+binding).
    - Verifier challenges on one edge `e ∈ E`.
    - Prover reveals `φ'(v) || r_v` for both endpoints.
    - Verifier checks colors are distinct and recomputes commitments.
    - Repeat `|E|^2` times.
- **Properties**: correctness clear; special soundness gives valid 3-coloring `φ'`; HVZK simulator picks `e`, two distinct random colors, random `r_v`. HVZK is only **computational** (powerful adversary could invert `f`).

## 5.6 AND and OR Compositions

- **AND** (`L_0 ∧ L_1`): run both proofs sequentially or in parallel; correctness/soundness/HVZK clear.
- **OR** (`L_0 ∨ L_1`), naïve: run a real proof for the known witness and a simulated proof for the other. Issue: the verifier learns **which** side is true (which side has fixed challenge first).
- **Cramer-Damgaard-Schoenmakers OR-proof**:
    - Send `α_0, α_1` together first round.
    - Verifier sends single challenge `β`.
    - Prover splits `β = β_0 ⊕ β_1`: chooses `β_{1-b}` freely (for simulation), forces `β_b = β ⊕ β_{1-b}`.
    - Sends `β_0, β_1, γ_0, γ_1`.
    - Verifier checks `β_0 ⊕ β_1 = β` and both `V_i(α_i, β_i, γ_i) = 1`.
- **Soundness**: from two transcripts with `β ≠ β'`, at least one `b` has `β_b ≠ β_b'`; run the underlying special-soundness extractor.
- **Generalization**: “one-out-of-`n`” proofs use `n-1` simulated transcripts and one real transcript; complexity linear in `n`.

## 5.7 ZK for DLP-Related Relations

### 5.7.1 Schnorr Identification Protocol

- Setup: `G` finite group of prime order `q`, generator `g`; private `x`, public `h = g^x`.
- **Protocol**:
    - Prover picks random `r`; sends `R = g^r`.
    - Verifier sends random challenge `c`.
    - Prover answers `s = r + xc mod q`.
    - Verifier accepts iff `g^s = R·h^c`.
- **Worked example** in `Z_{11}^*`: subgroup `G = {1, 3, 4, 5, 9}` of order 5, generator `g = 5`, `x = 4`, `h = 9`. Random `r = 3`: `R = 4`. Challenge `c = 2`. `s = 3 + 2·4 = 1 mod 5`. Verify `g^s = 5 = 4·9^2 mod 11 = R·h^c`. ✓
- **Special soundness**: from `(R, c, s)` and `(R, c', s')`, `x = (s' - s)/(c' - c)`.
- **HVZK**: simulator picks `s, c`, computes `R = g^s·h^{-c}`.
- **Optimizations**:
    - `(r, R)` precomputable.
    - `c` may be small (efficiency boost) — but `s` then non-uniform; needs an extra assumption.
    - Useful for low-power provers (RFID).

### 5.7.2 Chaum-Pedersen Protocol (DH-Tuples)

- Two groups `G_1, G_2` of prime order `q`. Statement: `h_1 = g_1^x ∧ h_2 = g_2^x`.
- **Protocol**: run two Schnorrs in parallel sharing the same `r, c, s`.
    - Prover: random `r`; `R_1 = g_1^r`, `R_2 = g_2^r`.
    - Verifier: random `c`.
    - Prover: `s = r + cx`.
    - Verifier: `g_1^s = R_1·h_1^c`, `g_2^s = R_2·h_2^c`.
- **Application**: prove `(g, g^a, g^b, g^{ab})` is a DDH tuple.
- **For ElGamal** `(c_1, c_2) = (m·h^r, g^r)`: prove `(c_1, c_2)` is an encryption of `m`
    - Knowing secret `x`: `g_1 = g, h_1 = h, g_2 = c_2, h_2 = c_1·m^{-1}`.
    - Knowing randomness `r`: `g_1 = g, h_1 = c_2, g_2 = h, h_2 = c_1·m^{-1}`.
- **E-voting**: voter encrypts `0`/`1`, proves well-formedness via OR of two Chaum-Pedersen proofs; election authority decrypts the homomorphic sum and proves correctness.

## 5.8 Fiat-Shamir Transform — Removing Interaction

- **Heuristic**: replace verifier’s challenge with `H(x, α)` for a hash `H` modeled as a random oracle.
- **Non-interactive proof**: `π = (α, γ)` (prover sends both).
- **Verifier**: recomputes `β = H(x, α)`, checks `V(x, α, β, γ) = 1`.
- **Security**: provable in the random-oracle model. SHA is not a random function in practice, so the intuition is a heuristic without rigorous proof.

## 5.9 From Identification to Signatures

- Apply Fiat-Shamir to an identification protocol, with the message `m` mixed into the hash:
    - **Sign(m)**: `α = P(x, w)`; `β = H(m, PK, α)`; `γ = P(x, w, α, β)`; output `(α, γ)`.
    - **Verify(m, σ)**: recompute `β`, check `V(x, α, β, γ) = 1`.
- **Optimization**: if `α` can be recomputed from `(β, γ)`, send `(β, γ)` instead.
- **Schnorr signatures** = Fiat-Shamir on Schnorr ID:
    - KeyGen: `G, g, q, x, h = g^x`.
    - Sign(m): random `r`; `R = g^r`; `c = H(m, g, h, R)`; `s = r - xc`; output `(c, s)`.
    - Verify: `R' = g^s·h^c`; accept iff `c = H(m, g, h, R')`.
- **Existential unforgeability under chosen-message attacks**: under random-oracle assumptions and DLP hardness.

---

# 6. Cryptanalysis & Attack Techniques

## 6.1 Cryptography vs Cryptanalysis

- Cryptography ensures private and authenticated communications; cryptanalysis breaks it. **Good criminals make good policemen too.**
- **Why cryptanalysis matters**:
    - Confidence in hardness assumptions.
    - Benchmarks to choose key sizes.
    - Design lessons from successful attacks.

## 6.2 The Cryptanalyst’s Toolbox

- Computational number theory, birthday attacks, linear and differential cryptanalysis, generic DLP algorithms, index calculus, lattice reduction, Gröbner bases, SAT solvers — anything that helps.
- Hardware: laptops, servers, FPGAs, dedicated hardware, **Sony PlayStations** (advanced MD5 attacks → Nostradamus attack), cloud, mobile phones.
- **Public challenges**: RSA factoring (closed 2007), Certicom ECDLP (solved up to 109 bits), Darmstadt lattice, Fukuoka MQ — “Hall of Fame” entries.
- **Recommended key lengths**: see www.keylength.com; balance short-term/long-term security and adversary capability (NSA vs little brother), plus Moore’s law and algorithmic progress.

## 6.3 Birthday Paradox

- 23 people: 50% chance of shared birthday. Generally, choosing `N_2 ≈ √N` random elements from a set of size `N` yields a collision with probability `≈ 1 - e^{-N_2(N_2-1)/N}`.
- **Hash-collision algorithm**: hash random messages until collision; expected `O(2^{n/2})` for an `n`-bit hash.

## 6.4 Generic DLP Algorithms

- **Exhaustive search**: `O(|G|)` worst case, `|G|/2` average.
- **Baby-Step-Giant-Step (BSGS)**: write `k = jN' + i` with `N' = ⌈√|G|⌉`. Compute `L_B = {g^i}`, `L_G = {h·g^{-jN'}}`; intersect. Time and memory `O(√|G|)`.
- **Pollard’s rho** (collision-finding): partition `G = G_1 ∪ G_2 ∪ G_3`; iterate

        f(z) = z·g  if z ∈ G_1
        f(z) = z^2  if z ∈ G_2
        f(z) = z·h  if z ∈ G_3

  Track `(a_i, b_i)` such that `g_i = g^{a_i}·h^{b_i}`; collision gives `x = -(a_1 - a_2)/(b_1 - b_2) mod |G|`. Floyd’s improvement: tortoise/hare comparison, `O(1)` memory.
- **Pohlig-Hellman**: if `|G| = ∏ p_i^{e_i}`, solve DLP in each subgroup `(g^{|G|/p_i^{e_i}})^k = h^{|G|/p_i^{e_i}}`, then combine via CRT. **Smooth groups → easy DLP.** Countermeasure: large prime-order group.
    - Worked example: `p = 11`, `g = 2` (generator of `F_p^*`, order `10 = 2·5`). For `h = 7`: `g^5 = 10`, `h^5 = 10` ⇒ `x ≡ 1 mod 2`; `g^2 = 4`, `h^2 = 5` ⇒ `x ≡ 2 mod 5`; CRT ⇒ `x = 7`.
- **Chinese Remainder Theorem (constructive)** via Extended Euclid: for `n = p_1 p_2`, `1 = p_1·(p_1^{-1} mod p_2) + p_2·(p_2^{-1} mod p_1)`, then `x = x_2·p_1·(p_1^{-1} mod p_2) + x_1·p_2·(p_2^{-1} mod p_1)`. Generalizes to `n = ∏ p_i^{e_i}`.
- **Extended Euclid algorithm**: recursive form `gcd(a, b) → gcd(b, a - qb)`, returns `(d, r, s)` with `ar + bs = d`. Complexity `O(|a|^2)`, best `O(|a| log |a|)`. Worked example: `gcd(31, 11)`: `9 = 1·31 - 2·11`, `2 = -1·31 + 3·11`, `1 = 5·31 - 14·11`.
- **Generic-group lower bound**: for any group `G` of order with largest prime factor `q`, generic algorithms cost at least `O(√q)` group operations.

## 6.5 Index Calculus and Subexponential L-Notation

- **L-notation**: `L_p(α, c) = exp((c + o(1))·(log p)^α·(log log p)^{1-α})`. Bridges polynomial (`α=0`) and exponential (`α=1`).
- **Best DLP in F_p^*** : `L_p(1/3, (64/9)^{1/3})` (number field sieve / function field sieve analogue). Same for factoring in `Z`.
- **F_{2^n}**: quasi-polynomial since 2013 — broken in theory and practice.
- **Index-calculus framework**:
    - Choose factor base `F ⊂ G` containing a generator.
    - Find ~|F| relations `∏ f_i^{a_{i,j}} = 1` between factor-base elements.
    - Linear algebra over `Z/|G|Z` recovers `log_g f_i` for all `f_i`.
    - Special step then recovers `log_g h`.
- **Naive index calculus for F_p^***:
    - Factor base = primes ≤ B plus `h`.
    - Sample `r_j = g^{a_j}·h^{b_j}`; if `r_j` is `B`-smooth, get a relation.
    - Linear algebra produces `(a, b)` with `g^a·h^b = 1`, hence DLP.
- **Naive analysis**: pick `log B ≈ (log p)^{1/2}`. `|F| ≈ 2^{(log p)^{1/2}}`; smoothness probability `ρ(u) ≈ 2^{-(1/2)(log p)^{1/2} log log p}`; total cost ≈ `2^{(1/2 + o(1))(log p)^{1/2}(log log p)}`. Better choice `B ≈ L_p(1/2, c)` yields slightly better `L_p(1/2, c')` cost; sieving / NFS push to `L(1/3)`.
- **ECDLP state of the art**: `L(2/3)` algorithms exist for `F_{q^n}` if `q` and `n` are right size; for prime fields and `F_{2^n}` with `n` prime, current best is **generic** `O(√|G|)`.

## 6.6 DLP Variants and Factoring

- **CDH ↔ DLP** roughly equivalent (Maurer); see Section 3.6.
- **DDH may be easy where CDH is hard** (pairing-friendly elliptic curves):

        (P, aP, bP, cP) DDH tuple ⇔ e(P, cP) = e(aP, bP)

- **“Variants” of DLP/CDH** invented for provable-security needs (e.g., One-Sided Modified SSCDH); only cryptanalysis can give confidence.
- **Generic group model**: standard practice to argue variant hardness — but not a real proof.
- **Factoring algorithms**:
    - **Pollard’s rho for factoring**: iterate pseudorandom `f`; track `gcd(x_i - x_{2i}, n)` ≠ 1; succeeds in `O(p^{1/2})`.
    - **Pollard’s p−1 method**: assume `p − 1` is `B`-powersmooth and `q − 1` is not. Let `s = ∏ p_i^{e_i}` over primes `≤ B`; `g^s ≡ 1 mod p` so `p | gcd(g^s - 1, n)`. **Elliptic-Curve Method (ECM)** removes the smoothness constraint by working on random curves.
    - **Quadratic sieve (QS)**: `L_n(1/2)`. **General Number Field Sieve (NFS)**: `L_n(1/3)`. **ECM**: `L_p(1/2)`.
- **Coppersmith’s method**: lattice reduction to find small roots of polynomials mod `n`; used in RSA small `d`/small `e` attacks.

## 6.7 Cache-Timing Attacks

- **Black-box vs grey-box**: side-channel attacks turn the algorithm from a black box into a grey box revealing partial internal computations.
- **PIN-check toy example**: a sequential character-by-character `if (pin[i] == ...)` reveals matched prefix length via execution time. Timing attacks exploit any relationship between execution time and a secret.
- **AES T-box implementation** (Rijndael’s software speedup):
    - Standard AES: separate sbox, ShiftRows, MixColumns, AddRoundKey.
    - T-box trick: merge SBox + ShiftRows + MixColumns into 4 lookup tables `T_0, ..., T_3`, each 256 entries × 4 bytes = 1024 B (4 KB total).
    - Round expression:

            (e_{0,j}, ..., e_{3,j})^T = T_0(a_{0,j}) ⊕ T_1(a_{1,j-C_1}) ⊕ T_2(a_{2,j-C_2}) ⊕ T_3(a_{3,j-C_3}) ⊕ (k_{0,j}, ..., k_{3,j})^T

      with AES-128 shifts `C_1 = 1, C_2 = 2, C_3 = 3`, `j-C = (j-C) mod 4`.
- **Bernstein-style cache-timing attack on AES**:
    - First-round T-box index: `a_{0,0} = p_{0,0} ⊕ k_{0,0}`. Cache hit/miss on `T_0(a_{0,0})` depends on `a_{0,0}`. Time `T_0(0)` vs `T_0(7)`: first is a cache miss (slow), second a hit (fast).
    - **Profile phase** (server with known key `k`):
        1. Send `n` random plaintexts; record times `t_1, ..., t_n`.
        2. Average `μ = (1/n) Σ t_i`.
        3. Group times by `p_{0,0}`: `G_v = { t_i | p_{0,0} = v }`.
        4. Compute group means `μ_v` and deviations `δ_v = μ_v - μ`.
        5. Find `p_max = argmax(δ_v)` — slowest lookup.
        6. Recover `a_max = k_{0,0} ⊕ p_max` for the profiled key.
    - **Attack phase** (target with unknown `k'`, same hardware):
        1. Repeat the timing collection on the target.
        2. Get `p'_max = argmax δ'_v`.
        3. Since same hardware ⇒ same `a_max`, deduce `k'_{0,0} = a_max ⊕ p'_max`.
- **Notes**:
    - Executable **remotely over the network** (round-trip time suffices).
    - Many T-box-based AES libraries (incl. OpenSSL historically) were vulnerable.
- **Countermeasures**:
    - **Random delays**: Central Limit Theorem — averaging over `n` measurements brings noise std down by `√n`, so attack only slowed.
    - **Constant-time execution**:
        - Custom hardware enforcing constant-time memory access (slower).
        - AES without lookup tables (slower in software).
        - Carefully model cache behavior to avoid time-dependent hits/misses (hard with proprietary CPUs).

## 6.8 Fault Injection and Differential Fault Analysis

### 6.8.1 Active Adversary Model

- Side-channel attacks are passive; **fault attacks** are active — adversary modifies the computation.
- **Fault-injection targets**:
    - **Stuck-at faults in control logic** (e.g., AES round counter stuck at `i = 1` ⇒ very weak encryption, only one round).
    - **Instruction skip**: faulting opcode → CPU treats unknown opcode as `nop`. Example: skip `callq .PIN_Check_function;` → PIN check bypassed.
- **Injection techniques**:
    - **Voltage glitching**: tiny under/over-voltage; non-invasive; simple, effective; coarse.
    - **Laser fault injection**: focused beam; semi-invasive (chip decapsulation); fine-grained but parameter search expensive.
    - Other techniques mentioned: clock-frequency glitch, temperature, X-ray / ion beams.
- **Fault model categorization**:
    - **Granularity**: single bit / multi-bit / multi-byte.
    - **Modification**: random bit-flip / biased / stuck-at-0 / stuck-at-1.
    - **Control**: spatial (small region vs large) and temporal (precise vs imprecise).
    - **Duration**: transient / persistent / permanent.

### 6.8.2 Differential Fault Analysis on DES (Biham-Shamir 1997)

- **Setup**: encrypt the same plaintext `P` once normally (`C = enc(P, K)`) and once with a fault (`C' = enc'(P, K)`); analyze `C ⊕ C'`.
- **Fault model**: random bit-flips on right half `R_15` (32 bits) at the start of round 16 — transient, low-control. Feistel propagation:

        L_16 = R_15
        R_16 = L_15 ⊕ f(R_15, K_16)
        C = FP([L_16, R_16])

  Faulted: `R'_15 = R_15 ⊕ ε` ⇒ `L'_16 = R'_15`, `R'_16 = L_15 ⊕ f(R'_15, K_16)`, `C' = FP([L'_16, R'_16])`.
- **Recovering the round key K_16**:
    1. Apply inverse final permutation: `[L_16, R_16] = FP^{-1}(C)`, `[L'_16, R'_16] = FP^{-1}(C')`.
    2. Fault differential `ΔR_16 = R_16 ⊕ R'_16 = f(L_16, K_16) ⊕ f(L'_16, K_16)`.
    3. `f` structure: expansion `E`, XOR with `K_16`, S-boxes `S_1, ..., S_8`, permutation `P`. `ΔR_16 = P(D ⊕ D')` with `D = (S_1(B_1), ..., S_8(B_8))` and `B_i = E_i(L_16) ⊕ K_{16}^i`.
    4. Linear inversion: `P^{-1}(ΔR_16) = D ⊕ D'`. Restrict to S-box `i`:

            P_i^{-1}(ΔR_16) = S_i(E_i(L_16) ⊕ K_{16}^i) ⊕ S_i(E_i(L'_16) ⊕ K_{16}^i)

    5. For each S-box (i = 1..8), brute-force the 6-bit subkey `K_{16}^i ∈ {0, ..., 63}` and test the equation. Keep candidates passing across many `(C, C')` pairs (intersection over `j`).
- **Strengths**: very strong attack with few faults; realistic fault model.
- **Requirements**: control of plaintext (constant `P` across the pair); observable ciphertexts.
- **Variants**: many fault models, different rounds, other ciphers (AES).

### 6.8.3 Beyond DFA

- **Statistical Fault Attacks (SFA)** (Fuhr et al.): work without plaintext control, using statistical bias of faulty ciphertexts.
- **Statistical Ineffective Fault Attacks (SIFA)** (Dobraunig et al., 2018): exploit **ineffective** faults — when the fault leaves output unchanged. Bypasses redundancy/error-detection countermeasures, since the comparison says “OK”.
- **Persistent Fault Attacks (PFA)** (Zhang et al.): require persistent (non-transient) faults, e.g., S-box table modified across encryptions; very simple analysis recovers the key.

### 6.8.4 Countermeasures and Their Limits

- **Redundancy**: encrypt twice and compare; defeats single transient faults; bypassable by SIFA.
- **Error detection / correction**: extend the cipher datapath with checksums.
- **Sensors**: voltage/laser detectors; may render the device useless on false positives.
- Ciphertext comparison itself can be faulted; certain ineffective faults bypass redundancy and error-detection schemes.

## 6.9 Selecting Cryptographic Key Lengths

- Easy for symmetric (key bits ≈ security bits); much harder for public key (subexponential algorithms).
- Tradeoff: efficiency vs security; account for Moore’s law, algorithmic progress, security margin; long-term vs short-term.
- See Lenstra–Verheul, “Selecting Cryptographic Key Sizes”, and www.keylength.com.

## 6.10 Cryptanalytic Extraction of Neural Networks (Model Stealing)

- **Model stealing / extraction** targets confidentiality of a deployed ML model. Attacker queries an API or observes physical leakage to build a substitute `f̂ ≈ f`.
- **Why it matters**: economic value (training cost), security value (offline analysis), privacy value (enables membership inference, model inversion).
- **Attacker goals**: high task **accuracy** vs high **fidelity** (matching `f` everywhere — needed for deeper analysis and follow-up attacks).
- **Attacker observations** range from label-only → label + confidence → top-k → full logits.
- **Three families**:
    - **Prediction-API attacks**:
        - Logistic regression `f(x) = 1 / (1 + e^{-(w^T x + b)})` ⇒ `log(f/(1-f)) = w^T x + b`. Solve a linear system to recover `(w, b)`.
        - Easy and practical for simple models; hard for deep nets directly.
    - **Cryptanalytic extraction** (the “DPA of NNs”):
        - **ReLU-network insight**: `ReLU(x) = max(0, x)`; each neuron is active or inactive depending on pre-activation sign. For a fixed activation pattern, the whole net is **affine**.
        - **Critical points**: input-space boundaries where one neuron flips; expose hidden-layer structure.
        - Toy example: `h(x) = ReLU(x - 2)` is 0 for `x < 2` and `x - 2` for `x ≥ 2`. The slope jump at `x = 2` is observable.
        - **Differential viewpoint**: small input deltas detect active/inactive flips, like differential cryptanalysis.
        - **Workflow**: (1) pick 1-D input directions; (2) search for critical points; (3) use local linearity to recover neurons; (4) recover layer-by-layer.
        - **Functional equivalence**: hidden units permute without changing output; goal is to recover the function, not exact parameter ordering.
        - **Achieved results**:
            - Crypto 2020: 100k-parameter MNIST ReLU net extracted with `2^{21.5} ≈ 3 M` queries in <1 hour, worst-case error `2^{-25}`. A 4k-parameter net needed `2^{18.5} ≈ 370k` queries, error `2^{-40.4}`. ~100× fewer queries and `2^{20}×` more precise than prior work.
            - Polynomial-time follow-up: CIFAR-10 net (3072 inputs, 8 hidden layers, 256 neurons/layer, >1M params); a step previously requiring `2^{256}` reduced to ~30 minutes on a 256-core machine.
            - Production LMs: extracted full projection matrix of OpenAI Ada, Babbage for under \$20; confirmed hidden dimensions 1024 and 2048; estimated <\$2,000 to recover gpt-3.5-turbo projection matrix.
    - **Side-channel attacks** on inference hardware:
        - Observe power / EM during inference on embedded device.
        - Repeated computation patterns reveal layer structure and neuron counts.
        - Timing differences distinguish activation functions (ReLU vs sigmoid vs tanh vs softmax).
        - **Correlation Power Analysis (CPA)**: with known input and a leakage model on multiplications, the correct weight stands out statistically.
        - **Layer-by-layer recovery**: first recover `L_0 → L_1` weights using CPA, count neurons by output sum widths, then recover activation timings, then proceed `L_1, ..., L_{N-1}`.
        - Case study (ARM Cortex M3 + MLP, MNIST, DPAv4): original 60.9% / 98.16% accuracy ≈ recovered 60.87% / 98.15%, average weight error `≈ 0.0025`.
- **Defenses**:
    - Restrict prediction outputs (label-only).
    - Monitor / rate-limit suspicious queries.
    - Watermarking / fingerprinting to detect stolen models.
    - Side-channel countermeasures on embedded inference.
    - Treat deployed models as confidential assets.

---

# 7. Post-Quantum Cryptography

## 7.1 Threat from Quantum Computers

- Currently used hard problems: integer factorization, DLP in `F_q^*`, ECDLP. **All broken in polynomial time on a quantum computer (Shor)**.
- **Shor’s factoring sketch**:
    - For `n = pq` (`p, q` of form `2p'+1, 2q'+1` with `p', q'` prime), pick random `a`. Define periodic `f(x) = a^x mod n`; period `T | φ(n) = 4p'q'`, often `p'q' | T`. Quantum Fourier transform extracts `T`. Guess `T = c·p'q'`, substitute, solve a quadratic to recover factors.
- **Shor’s DLP sketch**:
    - Define `f(r, s) = g^{-r}·h^s`; period `(t_1, t_2) ∈ Z_n^2` is a multiple of `(x, 1)`; recover `x = t_1 / t_2`.
- **Core engine**: quantum Fourier transform (FFT analogue) for period finding.
- **Impact**: breaks SSH, TLS, Signal, PGP. Lattices, polynomial systems, isogeny problems and hash functions are not known to be broken; NP-hard problems’ status quantum-wise also unknown; large quantum computers may or may not be buildable.
- **Grover’s algorithm**: `O(√N)` search; doubles the bit-length needed for symmetric keys / hash preimages.
- **Further impacts**:
    - Collision-finding might drop from `O(√N)` to `O(N^{1/3})` quantumly.
    - Quantum queries in superposition give stronger adversaries; standard security definitions need adapting.
    - Post-quantum security of Fiat-Shamir signatures and other constructions is unclear.

## 7.2 PQC Overview and NIST Process

- **PQC** approaches: lattices, codes, multivariate polynomials, isogenies, non-abelian groups, hash functions.
- Recommended by NSA, GCHQ.
- **NIST PQC competition timeline**:

| Date | Milestone |
|---|---|
| Dec 2016 | Call for proposals |
| Nov 2017 | 69 Round-1 submissions |
| Dec 2018 | 27 Round-2 |
| Jul 2020 | 7 finalists + 8 alternates Round 3 |
| Jun 2022 | KYBER, DILITHIUM, FALCON, SPHINCS selected; 4 KEMs to Round 4 |
| Aug 2024 | KYBER, DILITHIUM, SPHINCS standards published |
| Mar 2025 | HQC selected |

- **New signature competition** started June 2023 (Christophe Petit involved in **SQIsign** submission).
- **Selected schemes**:
    - **KYBER (ML-KEM)**: IND-CCA KEM via IND-CPA + CCA transform. Module-LWE; lattice problem with good speed-security tradeoff between “ideal LWE” and standard LWE; asymptotic hardness backed by reductions, concrete hardness “somewhat speculative”. Keys a few thousand bits.
    - **DILITHIUM (ML-DSA)**: signature based on identification + Fiat-Shamir-with-aborts. Module-LWE security. “High efficiency, relatively simple implementation, strong theoretical security basis, encouraging cryptanalytic history.”
    - **FALCON**: Fast Fourier Lattice-based Compact Signatures over NTRU (ideal lattices). Hash-then-sign paradigm. Short signatures and public keys; harder to implement in constant time.
    - **SPHINCS+**: hash-based, built on one-time signatures + Merkle trees; security relies on hash functions (SHA-2). Small keys, fast key gen, longer signatures.
    - **HQC** (Mar 2025): IND-CCA KEM via IND-CPA + Fujisaki-Okamoto. Quasi-cyclic moderate-density parity-check codes (QC-MDPC). Larger keys/ciphertexts than Kyber; assumption diversity.
- **Other previously-considered candidates**:
    - **BIKE**: similar to HQC, smaller but slower.
    - **Classic McEliece**: conservative KEM; very large keys.
    - **SIKE**: isogeny KEM; **broken** in 2022.
- **State of the art**:
    - **Lattices**: front-runner — efficient, versatile, well-studied; concrete parameters tricky.
    - **McEliece**: safe since 1978 but large keys (~8 MB).
    - **Multivariate**: very efficient signatures (UOV, MAYO); many encryption schemes broken.
    - **Isogeny**: smallest keys; substitute for ECDH; slow; signatures not yet practical except SQIsign.
    - **Hash-based**: safe but large; no encryption.
- **Standards still being adopted, securely implemented and deployed**; cryptanalysis continues; new signature competition aims at assumption diversity.

## 7.3 Other Post-Quantum Approaches

### 7.3.1 Multivariate Cryptography

- Solving polynomial systems over a finite field is NP-hard. Suitable for signatures (UOV, MAYO); encryption schemes have a poor track record.

### 7.3.2 Code-Based Cryptography (McEliece)

- **Idea**:
    - Pick a code with efficient decoding (Goppa, Reed-Solomon).
    - Secret = invertible transformation; public = “seemingly random” code.
    - Encryption: noisy encoding under public key.
    - Decryption: invert the secret transformation, then decode.
- **Goppa-based McEliece (1978)**: still safe; ~8 MB keys.
- Many shorter variants are broken; signature versions (4/6 broken in June 2023 PQC submissions); **Wave** and MPC-based proposals look promising.

### 7.3.3 Isogeny-Based Cryptography

- An **isogeny** is a rational map between elliptic curves that is also a group homomorphism. Used in point counting, DLP transfer, early protocols.
- **Endomorphism-ring problem**: foundational; studied by David Kohel’s 1996 PhD thesis.
- **Key agreement diagram**:

        E_0 → E_A = E_0/G_A (via φ_A)
        E_0 → E_B = E_0/G_B (via φ_B)
        E_0/⟨G_A, G_B⟩ obtained by combining φ'_A, φ'_B

- Schemes: **SIDH (†2022)**, **CSIDH** (still considered), encryption from key exchange, ID/signatures including **SQIsign**, and many recent protocols (some leveraging the SIDH attacks themselves).
- **Pros**: shortest PQC keys; drop-in for ECDH preserving forward secrecy; partial implementation reuse from ECC.
- **Cons**: more security analysis needed; relatively slow; signatures not yet fully practical (best: SQIsign).

## 7.4 Lattice-Based Cryptography (Deep Dive)

### 7.4.1 Why Lattices

- Worst-case to average-case reductions.
- Connection to NP-hard problems.
- No known quantum attacks.
- Assumption diversity.
- Faster solutions to existing primitives (encryption, signatures); first solutions to FHE and multilinear maps.

### 7.4.2 Lattices: Definitions

- **Lattice** `L`: discrete subgroup of `R^n`; `Σ a_i v_i ∈ L` for `a_i ∈ Z, v_i ∈ L`; “discrete” means an ε-ball at 0 contains no other lattice point.
- **Dimension** `n`; lattice is **integer** if all coords integer.
- **Basis** `{v_i}`: minimal set generating `L = {Σ a_i v_i | a_i ∈ Z}`. **Rank** `r` = basis size; **full rank** if `r = n`. Often represented as matrix `V ∈ R^{n × r}`; `L = {Vx | x ∈ Z^r}`.
- **Equivalent bases**: `U = VS` with `S ∈ Z^{r×r}`, `det S = ±1` (unimodular).
- **Fundamental parallelepiped** `P(B)`: `[0, 1)`-combinations of basis vectors; quotient `R^n / L`.
- **Determinant** `det(L) = √|det(B^T B)|`; equals `|det B|` if `n = r`; equals volume of `P(B)`; basis-independent.
- **Inner product / norm**: `⟨u, v⟩ = Σ u_i v_i`; `||v|| = √⟨v,v⟩`. Orthogonal basis ⇔ `B^T B` diagonal.

### 7.4.3 Hard Problems

- **SVP**: find `v ∈ L` with `||v|| = λ_1(L) = min_{v ≠ 0} ||v||`.
- **CVP**: given `t ∈ R^n`, find `v ∈ L` with `||v - t|| = d(t, L)`.
- **Successive minima** `λ_k(L)`: smallest `λ` with at least `k` linearly independent vectors of norm ≤ λ.
- **Convex Body Theorem**: for any convex symmetric `S` with `vol(S) > 2^n det(L)`, `S` contains a non-zero lattice point. Proof: consider `S' = {x | 2x ∈ S}`; volume condition gives `z_1, z_2 ∈ S'` with `z_1 - z_2 ∈ L`, hence `z_1 - z_2 ∈ S` by symmetry/convexity.
- **Minkowski’s 1st theorem**: `λ_1 < √n·(det L)^{1/n}` (apply Convex Body to a ball).
- **Minkowski’s 2nd theorem**: `(∏_{i=1}^n λ_i)^{1/n} < √n·(det L)^{1/n}`.
- **Gaussian heuristic**: `λ_1 ≈` radius of the ball with volume `det L`. For the Euclidean norm `V(B(0, R)) = π^{n/2}/(n/2)!·R^n`. Works for many cryptographic lattices.
- **Decision-SVP / Decision-CVP**: with rational threshold `r`. Equivalences:
    - Search ↔ decision SVP, CVP.
    - CVP ⇒ SVP; converse heuristically true.
- **Approximate SVP/CVP** with factor `γ`: easier as `γ` grows.
    - NP-hard for `γ < n^{1/log log n}`.
    - Unlikely NP-hard for `γ > √(n / log n)`.
    - **LLL** achieves `γ = 2^{(n-1)/2}` in poly time.
    - Cryptographic regime: `γ = n^c` with `c ≥ 1`.
- **Worst case vs average case**: NP-hardness is worst case; cryptography needs average-case hardness. **Lattices admit worst-case-to-average-case reductions** — a unique selling point.
- **Modular lattices**: `L ⊃ qZ^n` with `q < det(L)`. Used:

        L_{A, q} = { x ∈ R^n | A x ≡ 0 mod q }, A ∈ Z_q^{m × n}, n ≈ m log m

  (here columns of `A` are not lattice vectors).
- **SIS (Small Integer Solution)**: given `q, A, ν`, find small `x` with `Ax ≡ 0 mod q`, `||x|| ≤ ν`. Harder with fewer columns / more rows.
- **LWE (Learning With Errors)**:
    - `s ∈ Z_q^n`. Sample `(a, t)` with `a` uniform in `Z_q^n`, `e` uniform in `[-B, B]` (or Gaussian), `t = ⟨a, s⟩ + e`.
    - **LWE problem**: given many `(a_i, t_i)`, recover `s`. With `B = 0`, linear algebra suffices.
    - **As a CVP**: with matrix `A` of `a_i`, `As ∈ L` and `e = t - As` is short (bounded-distance decoding).
    - Generalizes Learning Parity with Noise (NP-hard from coding theory).
    - **Decision-LWE**: distinguish LWE samples from uniform.
- **Other lattice problems**: Gap-SVP (decision with gap), ISVP (find vectors at successive minima), and many others.

### 7.4.4 Ideal Lattices and Module Lattices

- **Ideal lattice**: `R = Z[x]/(f(x))` (often `f = x^n + 1, n = 2^e`). Encode vector `v` as polynomial `v(x)`; lattice generated by `x^i v(x) mod f`. Only `n` coefficients to store.
- **Modular property**: Hermite normal form yields some `q ∈ Z ∩ ⟨v(x)⟩`, hence `qZ^n ⊂ L`.
- **Crypto rule of thumb**: any structure that improves efficiency tends to decrease security. Recent results: approximate-SVP for ideal lattices is **easier** than for general lattices, but no impact on Ring-LWE so far.
- **NIST schemes**: FALCON uses ideal lattices; Kyber, Dilithium use **module lattices** for a sweet spot.

### 7.4.5 Cryptographic Constructions

- **Ajtai’s hash function**: choose random modular lattice `L_{q, A}`; define `H : {0,1}^n → Z_q^m, x → Ax mod q`. Collision `Ax = Ax'` gives `(x - x') ∈ {-1, 0, 1}^n` with `A(x - x') = 0 mod q` — a SIS solution on average.
- **Worst-case to average-case for SIS** (sketch):
    - Goal: solve any `Õ(n)`-SIVP using a SIS solver.
    - Take a basis `B` defining an SIVP problem; consider `P(B)` divided into `q^n` cells; map cells to `Z_q^n` via `f(r) = ⌊q B^{-1} r⌉`.
    - **Lemma (informal)**: large enough random vectors mod `B` are uniformly distributed on `P(B)` (Gaussians of `σ = c λ_n`).
    - Provide `q, a_i = f(r_i)` to SIS solver; receive `z_i ∈ {-1, 0, 1}` with `Σ a_i z_i = 0 mod q`. Deduce lattice point `z = Σ r_i z_i` with `||z|| ≤ c n λ_n`. Guess `λ_n` via binary search or current best approximation.
- **Why circulant matrices for ideal lattices are bad**: lattice corresponds to `⟨a(x)⟩ ⊂ Z[x]/(x^n - 1)`. If `gcd(a(x), x^n - 1) ≠ 1`, exists `z_0 ≠ 0` with `a(x)·z_0(x) = 0 mod (x^n - 1)` ⇒ collision `(z, z + z_0)` for every `z`. Replace `x^n - 1` by an irreducible polynomial; `f(x) = x^n + 1, n = 2^k` enables FFT.
- **GGH cryptosystem (sketch)**:
    - Private = good basis (short, near-orthogonal); public = bad basis (e.g., Hermite normal form).
    - Encrypt small `m`: `c = As + m`, with `s` chosen so `c` is reduced mod Hermite basis.
    - Decryption is bounded-distance decoding (CVP-like) — easy with private basis (Babai’s nearest-plane), hard otherwise.
    - Probabilistic version: pad with random noise (`m → m + 2r`).
    - **Caveats**: no formal reduction; original parameters broken; not CCA secure (re-randomize a ciphertext, query oracle); apply Fujisaki-Okamoto for CCA. Eventually led to LWE schemes.
- **NTRU (sketch)**:
    - Coprime `p << q`; `R = Z[X]/(X^n - 1)`.
    - Private: small `f, g ∈ R` with `f` invertible mod `p` and mod `q`.
    - Public: `h = p f^{-1} g mod q`.
    - Encrypt small `m`: random small `r`; `c = m + h·r mod q`.
    - Decrypt: `m' = (c·f mod q)·f^{-1} mod p`.
    - Correctness: `cf = m f + p g r` mod `q`; with small RHS, no reduction occurs.
    - **Lattice link**: public key matrix

            A = [[I, 0], [H, qI]]

      with `H` cyclic for `h`. Private = matrix

            B = [[F, F̃], [G, G̃]]

      with `F, G` cyclic for `f, g`. `L(A) = L(B)`. Encryption is `(-r, m)^T` mod `L(A)`.
    - **Security**: original scheme has no proof; properly generated secret polynomials make it CPA secure under ideal-lattice assumptions (Stehlé–Steinfeld 2011). Recommended parameters published on NTRU website.
- **LWE-based encryption (Regev-style)**:
    - Parameters: `n, m, ℓ, t, r, q`, real `α > 0`.
    - Define `f : Z_t^ℓ → Z_q^ℓ : z → ⌊(q/t) z⌉`, “rounded scaling” (`q > t`); inverse `f_{-1}(z) = ⌊(t/q) z⌉`.
    - Private key: `S ∈ Z_q^{n × ℓ}` uniform.
    - Public key: `(A, P) ∈ Z_q^{m × n} × Z_q^{m × ℓ}` with `P = AS + E`, `A` uniform, `E` Gaussian (`σ = α q / √(2π)`).
    - Encrypt `v ∈ Z_t^ℓ`: random `a ∈ {-r, ..., r}^m`; output `(u, c) = (A^T a, P^T a + f(v))`.
    - Decrypt `(u, c)`: `v' = f_{-1}(c - S^T u)`.
    - Correctness: `c - S^T u = E^T a + f(v)`; `f_{-1}` recovers `v` while `||E^T a||_∞ < q/(2t)`.
    - Security: distinguishing `(A, P)` from uniform = decision-LWE; encryption with random `(A, P)` leaks nothing if `(2r+1)^m >> q^{n+ℓ}`. Together ⇒ CPA. CCA via Fujisaki-Okamoto or direct. Concrete LWE hardness: Albrecht-Player-Scott estimator.
- **Lattice signatures (basic idea)**:
    - Private = good basis; public = bad basis. Hash `H : * → R^n` collision-resistant.
    - Sign `m`: compute `H(m)`, run Babai’s nearest-plane to get close `s ∈ L`.
    - Verify: `s` and `H(m)` are close.
    - Examples: GGH signatures, NTRU signatures.
- **Nguyen-Regev attack on naive lattice signatures**:
    - Each signature `(m, s)` leaks `s - H(m)` uniformly distributed in (a translation of) `P(B)`.
    - From many signatures, an attacker recovers `B` via an optimization problem.
    - **Fix**: signature should be a slightly farther vector (distance `≈ c λ_n`) such that `s - H(m)`’s distribution is independent of `B` (Gaussian sampling).

---

# 8. Cross-Cutting Conclusions

- E-voting elegantly combines homomorphic encryption, ZK proofs, threshold cryptography, mixnets, and Fiat-Shamir — but real-world adversaries (PDFs in Helios, malware on DREs, weak randomness, side-channels, faults) repeatedly defeat purely cryptographic guarantees.
- Provable security yields strong but conditional assurances; cryptanalysis remains essential to test the conditions (subgroup choices, problem variants, RNG quality, implementation hygiene).
- Cryptanalysis is broad: number-theoretic algorithms (Pollard rho, BSGS, Pohlig-Hellman, index calculus, NFS, ECM), lattice reduction (LLL, BKZ), differential/linear cryptanalysis, side-channel (timing, cache, EM, power) and fault attacks (DFA, SFA, SIFA, PFA), and even cryptanalytic extraction of neural networks.
- Post-quantum cryptography is the long-term answer to Shor’s threat. Lattices lead, with KYBER, DILITHIUM, FALCON now standardized; SPHINCS+ adds hash-based diversity; HQC adds code-based diversity. Multivariate, isogeny (notably SQIsign), and code-based families round out the toolbox; all need continuing analysis, careful implementation, and secure deployment.
- Whether for democracy, banking, or AI APIs, **deployed crypto is only as strong as the weakest link in the chain — proof, problem, parameters, randomness, code, hardware, and humans**.
