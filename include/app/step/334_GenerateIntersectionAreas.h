#ifndef _APP_STEP_GENERATEINTERSECTIONAREAS_H_
#define _APP_STEP_GENERATEINTERSECTIONAREAS_H_

#include <epg/step/StepBase.h>
#include <app/params/ThemeParameters.h>

namespace app{
namespace step{

	class GenerateIntersectionAreas : public epg::step::StepBase< app::params::ThemeParametersS > {

	public:

		/// \brief
		int getCode() { return 334; };

		/// \brief
		std::string getName() { return "GenerateIntersectionAreas"; };

		/// \brief
		void onCompute( bool );

		/// \brief
		void init();

	};

}
}

#endif