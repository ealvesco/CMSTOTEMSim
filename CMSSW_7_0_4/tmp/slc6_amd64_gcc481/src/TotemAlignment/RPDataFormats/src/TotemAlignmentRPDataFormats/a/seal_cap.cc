static  const char* clnames[] = {
  "LCGReflex/RPAlignmentCorrection",
  "LCGReflex/RPAlignmentCorrections",
  "LCGReflex/LocalTrackFit",
  "LCGReflex/edm::Wrapper<LocalTrackFit>",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
