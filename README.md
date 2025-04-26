# 5G NR Positioning and Future Extensions (Rebuild)

This project rebuilds and extends an open 5G NR positioning simulation, focused on NRPPa over NGAP communication, and incorporates future development concepts for robust wireless localization.

We reconstruct and modernize the project for easier extensibility, research-grade experiments, and integration with real-world datasets.

---

## 📡 Project Overview

The goal of this repository is to provide a modular and ready-to-use simulation platform for:
- 5G NR-PPa positioning signaling over NGAP
- Uplink TDoA-based localization using OpenAirInterface-style networks
- Scenario testing for indoor and urban environments (LOS/NLOS)
- Integration of real-world datasets for validation

It enables simulation and research on:
- Multi-base station (gNB) based positioning
- NRPPa protocol messaging between NG-RAN, AMF, and LMF
- Handling multipath, interference, and non-line-of-sight challenges

---

## 📂 Dataset and Credits

This project uses real 5G positioning data from [Zenodo Record #15261338](https://zenodo.org/records/15261338), originally created by **Nico Kalis**.
The dataset has been organized under the `/datasets` directory for easy access.

---

## 🚀 Features
- Full end-to-end UL-TDoA signaling flow simulation
- Implemented key 5G interfaces:
  - NR-Uu
  - NG-C
  - NLs
- Core protocols covered:
  - NRPPa
  - NGAP
- Message sequence: SRS trigger ➔ UL measurement ➔ NRPPa signaling ➔ UE positioning
- Support for LOS/NLOS simulations using imported maps and visibility models
- Scripts for dataset preprocessing and synthetic test generation

---

## 🛣️ Future Developments (Inspired by Section 14)

The next evolution steps planned:
- Hybrid Machine Learning Localization: Use AI/ML models to distinguish LOS/NLOS conditions dynamically.
- Adaptive Positioning Algorithms: Real-time adjustment based on radio environment (e.g., industrial vs. urban).
- 6G Early-Stage Research: Extend framework toward preliminary 6G positioning standards.
- Security Layer Enhancements: Encrypt positioning-related data to address privacy concerns.
- Benchmarking Automation: Enable large-scale performance benchmarking across different network setups.
- OpenAirInterface Expansion: Deeper integration with real OAI deployments for live field-testing.

---

## ⚙️ How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/shariquetelco/5g-nr-positioning-future-extensions.git
   cd 5g-nr-positioning-future-extensions
