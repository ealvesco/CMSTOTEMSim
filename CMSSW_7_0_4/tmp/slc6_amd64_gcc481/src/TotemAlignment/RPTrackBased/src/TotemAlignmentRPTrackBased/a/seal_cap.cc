static  const char* clnames[] = {
  "LCGReflex/MillepedeAlgorithm",
  "LCGReflex/AlignmentTask",
  "LCGReflex/AlignmentConstraint",
  "LCGReflex/IdealResult",
  "LCGReflex/SingularMode",
  "LCGReflex/AlignmentGeometry",
  "LCGReflex/JanAlignmentAlgorithm",
  "LCGReflex/LocalTrackFitter",
  "LCGReflex/DetGeometry",
  "LCGReflex/std::vector<TGraph*>",
  "LCGReflex/std::vector<TH1D*>",
  "LCGReflex/std::vector<SingularMode>",
  "LCGReflex/std::vector<AlignmentConstraint>",
  "LCGReflex/std::set<unsigned int>",
  "LCGReflex/std::map<std::set<unsigned int>,JanAlignmentAlgorithm::ScatterPlot>",
  "LCGReflex/std::map<unsigned int,JanAlignmentAlgorithm::DetStat>",
  "LCGReflex/std::map<unsigned int,DetGeometry>",
  "LCGReflex/JanAlignmentAlgorithm::ScatterPlot",
  "LCGReflex/JanAlignmentAlgorithm::DetStat",
  "LCGReflex/std::map<unsigned int,TVectorT<double> >",
};
extern "C" void SEAL_CAPABILITIES (const char**& names, int& n )
{names = clnames;n = sizeof(clnames)/sizeof(char*);}
