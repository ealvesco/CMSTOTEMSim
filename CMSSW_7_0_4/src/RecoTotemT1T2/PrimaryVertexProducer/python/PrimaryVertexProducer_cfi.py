import FWCore.ParameterSet.Config as cms

primaryvertex = cms.EDProducer("PrimaryVertexFinder",
                                     SeeHits = cms.double(0.0),
                                     Verbosity = cms.int32(0),
                                     ChiOverNCut = cms.double(30.0),
                                     TrackRmin = cms.double(100.0),
                                     Telescopes = cms.int32(1),
                                     SeeTrack = cms.double(0.0),
                                     ZRange = cms.double(3000.0),
                                     ZCenter = cms.double(0.0),
                                     NumberOfTracks = cms.int32(100),
                                     FromOutside = cms.bool(False)                                     
                                      )

