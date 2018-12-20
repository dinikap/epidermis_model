//Header for biology modules created


#ifndef EPIDERMIS_BIOLOGY_MODULES
#define EPIDERMIS_BIOLOGY_MODULES

#include "biodynamo.h"

namespace bdm {

//Introduce an extracellular fluid -> Ca2++ that will determine the way the
//stem cells divide and grow into TA cells
enum Substances {calcium};

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

}

//TA cells
struct TransitAmplifying : public BaseBiology {
  TransitAmplifying() : BaseBiologyModule(gAllEventIds){}

  template <typename TEvent, typename TBm>
  TransitAmplifying(const TEvent& event, TBm* other, uint64_t newoid = 0) {}

  template <typename T, typename TSimulation = Simulation<>>
  void Run(T* cell) {


  }

}

//Dendritic cells
struct DendriticCell : public BaseBiology {

}


}
