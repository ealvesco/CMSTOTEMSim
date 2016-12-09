import FWCore.ParameterSet.Config as cms

T2CC = cms.EDProducer("T2CoincidenceProducer",
#    src = cms.InputTag("RawToDigi:T2PadDigi"),
     src = cms.InputTag("T2Digis:T2PadDigi"),
#    src = cms.InputTag("T2RawToDigi:T2PadDigi"),
    verbose = cms.uint32(0),
    quarter = cms.uint32(0),

    coincidenceChipConfig = cms.PSet(
      verbosity = cms.uint32(0),

      useControlRegisters = cms.bool(True),  # if True then the control numbers V,NP,OV... are not taken into account

      # default values of control registers for configuration of CC
      controlRegister1 = cms.uint32(7),
      controlRegister2 = cms.uint32(240),
      controlRegister3 = cms.uint32(0),

      # default values of control numbers for configuration of CC
      # following configuration is equivalent to 
      # controlRegister1=7; controlRegister2=240;  controlRegister3=0
      V  = cms.uint32(7),  # number of planes in "V out of NP" block
      NP = cms.uint32(0),  # NP = 1 means 5 planes, NP = 0 means 10 planes
      OV = cms.uint32(0),  # number of coordinate neighbour in "Or 1" block
      W  = cms.uint32(0),  # number of planes in "W out of NP" block
      Z  = cms.uint32(15), # controls "Z out of 8 or 16 block"
      O2 = cms.uint32(0),  # controls "Or 2" block
      LI = cms.uint32(0),  # 1 - inputs inverted, 0 - inputs not inverted (default)
      LO = cms.uint32(0),  # controls "And/Or 2" block
      AO = cms.uint32(0),  # controls "And/Or" block

      # CC logic
      useLogicWithWrongNP = cms.uint32(0)
   )
)


