//Header for biology modules created


#ifndef EPIDERMIS_BIOLOGY_MODULES
#define EPIDERMIS_BIOLOGY_MODULES

#include "biodynamo.h"

namespace bdm {

//Introduce an extracellular fluid -> Ca2++ that will determine the way the
//stem cells divide and grow into TA cells
enum Substances {calcium};

//First type of cell: Stem cells
//Stem cells will divide and grow to produce TA cells
struct StemCell : public BaseBiology {
  StemCell() : BaseBiologyModule(gAllEventIds){}

  template <typename TEvent, typename TBm>
  StemCell(const TEvent& event, TBm* other, uint64_t newoid = 0) {}

  template <typename T, typename TSimulation = Simulation<>>
  void Run(T* cell) {
    auto* sim = TSimulation::GetActive();
    auto* rm = sim->GetResourceManager();
    static auto* kDg = rm->GetDiffusionGrid(calcium);


  }

};

//TA cells
struct TransitAmplifying : public BaseBiology {
  TransitAmplifying() : BaseBiologyModule(gAllEventIds){}

  template <typename TEvent, typename TBm>
  TransitAmplifying(const TEvent& event, TBm* other, uint64_t newoid = 0) {}

  template <typename T, typename TSimulation = Simulation<>>
  void Run(T* cell) {


  }

};

//Differentiated cells
struct DifferentiatedCell : public BaseBiology {
  DifferentiatedCell() : BaseBiologyModule(gAllEventIds){}
};

//create a basement membrane along with the dermis
// BM should look like sine waves (best fit to actual data)
//Q: would i want to actually separate out dermis and BM?
struct BasementMembrane : public BaseBiology {
  BasementMembrane() : BaseBiologyModule(gAllEventIds){}
};

struct Dermis : public BaseBiology {

};

//From the basement membrane, cytokine are released into the environment

}
