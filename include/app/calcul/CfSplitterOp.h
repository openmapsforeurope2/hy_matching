#ifndef _APP_CALCUL_CFSPLITTEROP_H_
#define _APP_CALCUL_CFSPLITTEROP_H_

//SOCLE
#include <ign/feature/sql/FeatureStorePostgis.h>


//EPG
#include <epg/log/EpgLogger.h>
#include <epg/log/ShapeLogger.h>
#include <epg/tools/MultiLineStringTool.h>


namespace app{
namespace calcul{

	class CfSplitterOp {

	public:

	
		/// @brief 
		/// @param verbose 
		CfSplitterOp(
            bool verbose
        );

        /// @brief 
        ~CfSplitterOp();

        /// \brief
		static void compute(
			bool verbose
		);

    private:
		//--
		ign::feature::sql::FeatureStorePostgis*                  _fsArea;
        //--
		ign::feature::sql::FeatureStorePostgis*                  _fsCp;
		//--
		ign::feature::sql::FeatureStorePostgis*                  _fsCl;
		//--
		epg::log::EpgLogger*                                     _logger;
		//--
		epg::log::ShapeLogger*                                   _shapeLogger;
		//--
		bool                                                     _verbose;

	private:

		//--
		void _init();

        //--
		void _compute() const;

		//--
		std::pair<bool, ign::geometry::LineString> _computeSectionGeometry(
            ign::geometry::LineString const& sectionGeom, 
            ign::geometry::Polygon const& poly,
            epg::tools::MultiLineStringTool** mslToolPtr
        ) const;

		//--
		ign::geometry::LineString _computeCuttingLineGeometry(
            ign::geometry::LineString clGeom, 
            ign::geometry::Polygon const& poly
        ) const;

    };
}
}

#endif