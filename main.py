import asyncio
import logging
import platform
from typing import List, Dict
from dataclasses import dataclass

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)

# Simulated 5G network components
@dataclass
class UE:
    imsi: str
    guti: str
    position: Dict[str, float]  # {x, y, z} coordinates in meters

@dataclass
class GNB:
    global_id: str
    plmn: str
    cell_id: int
    trp_info: Dict[str, str]  # Transmission Reception Point info

@dataclass
class AMF:
    ip_address: str
    supported_plmns: List[str]

@dataclass
class LMF:
    ip_address: str
    routing_id: str

class FiveGNetworkSimulator:
    def __init__(self):
        self.ues: List[UE] = []
        self.gnbs: List[GNB] = []
        self.amf = AMF(ip_address="127.0.0.1", supported_plmns=["20895"])
        self.lmf = LMF(ip_address="127.0.0.1", routing_id="lmf_001")
        self.fps = 60  # Simulation frame rate

    async def setup_core_network(self):
        """Simulate starting OAI 5G core network (Docker-based)."""
        logger.info("Starting 5G core network...")
        # Simulate pulling and starting OAI Docker containers
        core_components = [
            "oai-nrf", "oai-amf", "oai-smf", "oai-udr",
            "oai-udm", "oai-ausf", "oai-upf", "oai-lmf"
        ]
        for component in core_components:
            logger.info(f"Starting {component}...")
            await asyncio.sleep(0.1)  # Simulate container startup delay
        logger.info("5G core network up and running.")

    async def setup_gnb(self):
        """Simulate gNB setup with NGAP connection to AMF."""
        gnb = GNB(
            global_id="gnb_001",
            plmn="20895",
            cell_id=14680064,
            trp_info={"trp_id": "trp_001", "position": "x:0,y:0,z:50"}
        )
        self.gnbs.append(gnb)
        logger.info(f"gNB {gnb.global_id} initialized with PLMN {gnb.plmn}.")

        # Simulate NG Setup procedure (3GPP TS 38.413)
        logger.info("Initiating NG Setup with AMF...")
        await self._send_ngap_message("NGSetupRequest", gnb, self.amf)
        await self._receive_ngap_message("NGSetupResponse", self.amf, gnb)
        logger.info("NG Setup completed.")

    async def setup_ue(self):
        """Simulate UE registration."""
        ue = UE(
            imsi="208950000000031",
            guti="",
            position={"x": 10.0, "y": 20.0, "z": 1.5}
        )
        self.ues.append(ue)
        logger.info(f"UE {ue.imsi} initialized at position {ue.position}.")

        # Simulate UE registration
        logger.info("Initiating UE Registration...")
        await self._send_nas_message("RegistrationRequest", ue, self.gnbs[0])
        await self._receive_nas_message("RegistrationAccept", self.amf, ue)
        ue.guti = "208950000000031_001"  # Assign GUTI
        logger.info(f"UE {ue.imsi} registered with GUTI {ue.guti}.")

    async def positioning_procedure(self):
        """Simulate NRPPa UL-TDoA positioning."""
        gnb = self.gnbs[0]
        ue = self.ues[0]
        logger.info("Starting UL-TDoA positioning procedure...")

        # Step 1: LMF initiates NRPPa PDU transfer
        logger.info("LMF sending NRPPa TRP Information Request...")
        nrppa_pdu = {"message_type": "TRPInformationRequest", "routing_id": self.lmf.routing_id}
        await self._send_ngap_message(
            "DownlinkNonUEAssociatedNRPPaTransport", self.lmf, gnb, payload=nrppa_pdu
        )

        # Step 2: gNB processes NRPPa PDU
        logger.info("gNB processing TRP Information Request...")
        trp_response = {
            "message_type": "TRPInformationResponse",
            "trp_info": gnb.trp_info,
            "timestamp": "2025-04-26T20:43:00"
        }
        await self._send_ngap_message(
            "UplinkNonUEAssociatedNRPPaTransport", gnb, self.amf, payload=trp_response
        )

        # Step 3: AMF forwards to LMF
        logger.info("AMF forwarding TRP Information Response to LMF...")
        await self._receive_ngap_message("N2InfoNotify", self.lmf, self.amf, payload=trp_response)

        # Simulate UL-TDoA calculation (simplified)
        logger.info("LMF calculating UE position using UL-TDoA...")
        estimated_position = {
            "x": ue.position["x"] + 0.1,  # Simulate small error
            "y": ue.position["y"] + 0.2,
            "z": ue.position["z"] + 0.05
        }
        logger.info(f"Estimated UE position: {estimated_position}")

    async def _send_ngap_message(self, message_type: str, sender, receiver, payload: Dict = None):
        """Simulate sending an NGAP message."""
        logger.info(f"Sending {message_type} from {sender.__class__.__name__} to {receiver.__class__.__name__}...")
        await asyncio.sleep(0.05)  # Simulate network delay

    async def _receive_ngap_message(self, message_type: str, receiver, sender, payload: Dict = None):
        """Simulate receiving an NGAP message."""
        logger.info(f"Received {message_type} at {receiver.__class__.__name__} from {sender.__class__.__name__}...")
        await asyncio.sleep(0.05)  # Simulate processing delay

    async def _send_nas_message(self, message_type: str, sender, receiver):
        """Simulate sending a NAS message."""
        logger.info(f"Sending NAS {message_type} from {sender.__class__.__name__} to {receiver.__class__.__name__}...")
        await asyncio.sleep(0.05)

    async def _receive_nas_message(self, message_type: str, receiver, sender):
        """Simulate receiving a NAS message."""
        logger.info(f"Received NAS {message_type} at {receiver.__class__.__name__} from {sender.__class__.__name__}...")
        await asyncio.sleep(0.05)

    async def update_loop(self):
        """Update simulation state."""
        logger.info("Updating simulation state...")
        await asyncio.sleep(0.1)

    async def run(self):
        """Main simulation loop."""
        logger.info("Starting 5G network simulation...")
        await self.setup_core_network()
        await self.setup_gnb()
        await self.setup_ue()
        await self.positioning_procedure()

        # Simulation loop
        while True:
            await self.update_loop()
            await asyncio.sleep(1.0 / self.fps)

async def main():
    simulator = FiveGNetworkSimulator()
    await simulator.run()

if platform.system() == "Emscripten":
    asyncio.ensure_future(main())
else:
    if __name__ == "__main__":
        asyncio.run(main())