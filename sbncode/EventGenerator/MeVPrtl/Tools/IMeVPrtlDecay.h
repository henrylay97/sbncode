/**
 *  @file   IMeVPrtlDecay.h
 *
 *  @brief  This is an interface for an art Tool which decays "Prtl" inside a
 *  detector volume. It maps MeVPrtlFlux to MeVPrtlDecay. 
 *
 *  @author grayputnam@uchicago.edu
 *
 */
#ifndef IMeVPrtlDecay_h
#define IMeVPrtlDecay_h

// Framework Includes
#include "fhiclcpp/ParameterSet.h"
#include "art/Framework/Principal/Event.h"

#include "sbnobj/Common/EventGen/MeVPrtl/MeVPrtlFlux.h"
#include "sbnobj/Common/EventGen/MeVPrtl/MeVPrtlDecay.h"

#include "IMeVPrtlStage.h"
#include "Constants.h"

// Algorithm includes

#include <utility>

//------------------------------------------------------------------------------------------------------------------------------------------

namespace evgen
{
namespace ldm {

/**
 *  @brief  IMeVPrtlDecay interface class definiton
 */
class IMeVPrtlDecay: virtual public IMeVPrtlStage
{
public:
    /**
     *  @brief  Virtual Destructor
     */
    virtual ~IMeVPrtlDecay() noexcept = default;

    virtual bool Decay(const MeVPrtlFlux &flux, const TVector3 &in, const TVector3 &out, MeVPrtlDecay &decay, double &weight) = 0;

protected:
    double TimeOfFlight(const MeVPrtlFlux &flux, TVector3 decay) {
      // TODO: should the neutrino TOF be subtracted here to get the correct T0?
      //
      // TODO: implement time of flight
      return 0.;
    }
};

} // namespace ldm
} // namespace evgen
#endif

