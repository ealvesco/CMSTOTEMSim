static  const char* clnames[] = {
  "LCGReflex/T2AlignmentCorrections",
  "LCGReflex/T2AlignmentCorrection",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
