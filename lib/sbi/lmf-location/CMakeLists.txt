cmake_minimum_required (VERSION 2.6...3.10.2)
project (CGenerator)

cmake_policy(SET CMP0063 NEW)

set(CMAKE_C_VISIBILITY_PRESET default)
set(CMAKE_CXX_VISIBILITY_PRESET default)
set(CMAKE_VISIBILITY_INLINES_HIDDEN OFF)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

find_package(OpenSSL)

if (OPENSSL_FOUND)
    message (STATUS "OPENSSL found")

    set(CMAKE_C_FLAGS "-DOPENSSL")
    if(CMAKE_VERSION VERSION_LESS 3.4)
        include_directories(${OPENSSL_INCLUDE_DIR})
        include_directories(${OPENSSL_INCLUDE_DIRS})
        link_directories(${OPENSSL_LIBRARIES})
    endif()

    message(STATUS "Using OpenSSL ${OPENSSL_VERSION}")
else()
    message (STATUS "OpenSSL Not found.")
endif()

set(pkgName "lmf_location")

# this default version can be overridden in PreTarget.cmake
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 1)

if( (DEFINED CURL_INCLUDE_DIR) AND (DEFINED CURL_LIBRARIES))
    include_directories(${CURL_INCLUDE_DIR})
    set(PLATFORM_LIBRARIES ${PLATFORM_LIBRARIES} ${CURL_LIBRARIES} )
else()
    find_package(CURL 7.58.0 REQUIRED)
    if(CURL_FOUND)
        include_directories(${CURL_INCLUDE_DIR})
        set(PLATFORM_LIBRARIES ${PLATFORM_LIBRARIES} ${CURL_LIBRARIES} )
    else(CURL_FOUND)
        message(FATAL_ERROR "Could not find the CURL library and development files.")
    endif()
endif()

set(SRCS
    src/list.c
    src/apiKey.c
    src/apiClient.c
    src/binary.c
    external/cJSON.c
    model/object.c
    model/access_token_err.c
    model/access_token_req.c
    model/access_type.c
    model/accuracy_fulfilment_indicator.c
    model/add_event_notify_datas.c
    model/add_location_datas.c
    model/additional_ue_info.c
    model/alert_limit.c
    model/area_event_info.c
    model/cancel_loc_data.c
    model/civic_address.c
    model/cm_state.c
    model/cm_state_any_of.c
    model/ecgi.c
    model/ellipsoid_arc.c
    model/ellipsoid_arc_all_of.c
    model/event_class.c
    model/event_notify_data.c
    model/event_notify_data_ext.c
    model/event_report_message.c
    model/event_reporting_status.c
    model/external_client_type.c
    model/fix_type.c
    model/gad_shape.c
    model/geographic_area.c
    model/geographical_coordinates.c
    model/gnss_id.c
    model/gnss_positioning_method_and_usage.c
    model/guami.c
    model/high_accuracy_gnss_metrics.c
    model/horizontal_velocity.c
    model/horizontal_velocity_with_uncertainty.c
    model/horizontal_with_vertical_velocity.c
    model/horizontal_with_vertical_velocity_and_uncertainty.c
    model/indoor_outdoor_ind.c
    model/input_data.c
    model/input_data_reporting_ind.c
    model/integrity_requirements.c
    model/invalid_param.c
    model/ipv6_addr.c
    model/lcs_broadcast_assistance_types_data.c
    model/lcs_priority.c
    model/lcs_qos_class.c
    model/lcs_up_connection_ind.c
    model/ldr_type.c
    model/loc_context_data.c
    model/loc_measurement_req.c
    model/loc_measurement_resp.c
    model/loc_measurements.c
    model/local2d_point_uncertainty_ellipse.c
    model/local2d_point_uncertainty_ellipse_all_of.c
    model/local3d_point_uncertainty_ellipsoid.c
    model/local3d_point_uncertainty_ellipsoid_all_of.c
    model/local_area.c
    model/local_origin.c
    model/location_data.c
    model/location_data_ext.c
    model/location_qo_s.c
    model/los_nlos_measure_ind.c
    model/lp_hap_type.c
    model/lp_hap_type_any_of.c
    model/mapped_location_qo_s_eps.c
    model/mbsr_info.c
    model/minor_location_qo_s.c
    model/model_2_d_relative_location.c
    model/model_3_d_relative_location.c
    model/motion_event_info.c
    model/ncgi.c
    model/nf_type.c
    model/nf_type_any_of.c
    model/no_profile_match_info.c
    model/no_profile_match_reason.c
    model/no_profile_match_reason_any_of.c
    model/occurrence_info.c
    model/periodic_event_info.c
    model/plmn_id.c
    model/plmn_id_nid.c
    model/point.c
    model/point_all_of.c
    model/point_altitude.c
    model/point_altitude_all_of.c
    model/point_altitude_uncertainty.c
    model/point_altitude_uncertainty_all_of.c
    model/point_uncertainty_circle.c
    model/point_uncertainty_circle_all_of.c
    model/point_uncertainty_ellipse.c
    model/point_uncertainty_ellipse_all_of.c
    model/polygon.c
    model/polygon_all_of.c
    model/positioning_method.c
    model/positioning_method_and_usage.c
    model/positioning_mode.c
    model/problem_details.c
    model/query_param_combination.c
    model/query_parameter.c
    model/range_direction.c
    model/ranging_sl_result.c
    model/redirect_response.c
    model/ref_to_binary_data.c
    model/related_ue.c
    model/related_ue_type.c
    model/relative_cartesian_location.c
    model/reported_event_type.c
    model/reporting_access_type.c
    model/reporting_area.c
    model/reporting_area_type.c
    model/reporting_ind.c
    model/reporting_ind_any_of.c
    model/response_time.c
    model/snssai.c
    model/supported_gad_shapes.c
    model/tai.c
    model/termination_cause.c
    model/tnap_id.c
    model/twap_id.c
    model/ue_area_indication.c
    model/ue_connectivity_state.c
    model/ue_lcs_capability.c
    model/ue_location_info.c
    model/ue_location_service_ind.c
    model/ue_up_positioning_capabilities.c
    model/uncertainty_ellipse.c
    model/uncertainty_ellipsoid.c
    model/up_config.c
    model/up_connection_status.c
    model/up_cum_evt_rpt_criteria.c
    model/up_loc_rep_addr_af_rm.c
    model/up_notify_data.c
    model/up_subscription.c
    model/usage.c
    model/velocity_estimate.c
    model/velocity_requested.c
    model/vertical_direction.c
    api/CancelLocationAPI.c
    api/DetermineLocationAPI.c
    api/LocationContextTransferAPI.c
    api/LocationMeasureAPI.c
    api/UPConfigureAPI.c
    api/UPSubscribeAPI.c
    api/UPUnsubscribeAPI.c

)

set(HDRS
    include/apiClient.h
    include/list.h
    include/binary.h
    include/keyValuePair.h
    external/cJSON.h
    model/object.h
    model/access_token_err.h
    model/access_token_req.h
    model/access_type.h
    model/accuracy_fulfilment_indicator.h
    model/add_event_notify_datas.h
    model/add_location_datas.h
    model/additional_ue_info.h
    model/alert_limit.h
    model/area_event_info.h
    model/cancel_loc_data.h
    model/civic_address.h
    model/cm_state.h
    model/cm_state_any_of.h
    model/ecgi.h
    model/ellipsoid_arc.h
    model/ellipsoid_arc_all_of.h
    model/event_class.h
    model/event_notify_data.h
    model/event_notify_data_ext.h
    model/event_report_message.h
    model/event_reporting_status.h
    model/external_client_type.h
    model/fix_type.h
    model/gad_shape.h
    model/geographic_area.h
    model/geographical_coordinates.h
    model/gnss_id.h
    model/gnss_positioning_method_and_usage.h
    model/guami.h
    model/high_accuracy_gnss_metrics.h
    model/horizontal_velocity.h
    model/horizontal_velocity_with_uncertainty.h
    model/horizontal_with_vertical_velocity.h
    model/horizontal_with_vertical_velocity_and_uncertainty.h
    model/indoor_outdoor_ind.h
    model/input_data.h
    model/input_data_reporting_ind.h
    model/integrity_requirements.h
    model/invalid_param.h
    model/ipv6_addr.h
    model/lcs_broadcast_assistance_types_data.h
    model/lcs_priority.h
    model/lcs_qos_class.h
    model/lcs_up_connection_ind.h
    model/ldr_type.h
    model/loc_context_data.h
    model/loc_measurement_req.h
    model/loc_measurement_resp.h
    model/loc_measurements.h
    model/local2d_point_uncertainty_ellipse.h
    model/local2d_point_uncertainty_ellipse_all_of.h
    model/local3d_point_uncertainty_ellipsoid.h
    model/local3d_point_uncertainty_ellipsoid_all_of.h
    model/local_area.h
    model/local_origin.h
    model/location_data.h
    model/location_data_ext.h
    model/location_qo_s.h
    model/los_nlos_measure_ind.h
    model/lp_hap_type.h
    model/lp_hap_type_any_of.h
    model/mapped_location_qo_s_eps.h
    model/mbsr_info.h
    model/minor_location_qo_s.h
    model/model_2_d_relative_location.h
    model/model_3_d_relative_location.h
    model/motion_event_info.h
    model/ncgi.h
    model/nf_type.h
    model/nf_type_any_of.h
    model/no_profile_match_info.h
    model/no_profile_match_reason.h
    model/no_profile_match_reason_any_of.h
    model/occurrence_info.h
    model/periodic_event_info.h
    model/plmn_id.h
    model/plmn_id_nid.h
    model/point.h
    model/point_all_of.h
    model/point_altitude.h
    model/point_altitude_all_of.h
    model/point_altitude_uncertainty.h
    model/point_altitude_uncertainty_all_of.h
    model/point_uncertainty_circle.h
    model/point_uncertainty_circle_all_of.h
    model/point_uncertainty_ellipse.h
    model/point_uncertainty_ellipse_all_of.h
    model/polygon.h
    model/polygon_all_of.h
    model/positioning_method.h
    model/positioning_method_and_usage.h
    model/positioning_mode.h
    model/problem_details.h
    model/query_param_combination.h
    model/query_parameter.h
    model/range_direction.h
    model/ranging_sl_result.h
    model/redirect_response.h
    model/ref_to_binary_data.h
    model/related_ue.h
    model/related_ue_type.h
    model/relative_cartesian_location.h
    model/reported_event_type.h
    model/reporting_access_type.h
    model/reporting_area.h
    model/reporting_area_type.h
    model/reporting_ind.h
    model/reporting_ind_any_of.h
    model/response_time.h
    model/snssai.h
    model/supported_gad_shapes.h
    model/tai.h
    model/termination_cause.h
    model/tnap_id.h
    model/twap_id.h
    model/ue_area_indication.h
    model/ue_connectivity_state.h
    model/ue_lcs_capability.h
    model/ue_location_info.h
    model/ue_location_service_ind.h
    model/ue_up_positioning_capabilities.h
    model/uncertainty_ellipse.h
    model/uncertainty_ellipsoid.h
    model/up_config.h
    model/up_connection_status.h
    model/up_cum_evt_rpt_criteria.h
    model/up_loc_rep_addr_af_rm.h
    model/up_notify_data.h
    model/up_subscription.h
    model/usage.h
    model/velocity_estimate.h
    model/velocity_requested.h
    model/vertical_direction.h
    api/CancelLocationAPI.h
    api/DetermineLocationAPI.h
    api/LocationContextTransferAPI.h
    api/LocationMeasureAPI.h
    api/UPConfigureAPI.h
    api/UPSubscribeAPI.h
    api/UPUnsubscribeAPI.h

)

include(PreTarget.cmake OPTIONAL)

set(PROJECT_VERSION_STRING "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

# Add library with project file with project name as library name
add_library(${pkgName} ${SRCS} ${HDRS})
# Link dependent libraries
if(NOT CMAKE_VERSION VERSION_LESS 3.4)
    target_link_libraries(${pkgName} PRIVATE OpenSSL::SSL OpenSSL::Crypto)
endif()
target_link_libraries(${pkgName} PUBLIC ${CURL_LIBRARIES} )
target_include_directories(
    ${pkgName} PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

include(PostTarget.cmake OPTIONAL)

# installation of libraries, headers, and config files
if (NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in)
    install(TARGETS ${pkgName} DESTINATION lib)
else()
    include(GNUInstallDirs)
    install(TARGETS ${pkgName} DESTINATION lib EXPORT ${pkgName}Targets)

    foreach(HDR_FILE ${HDRS})
        get_filename_component(HDR_DIRECTORY ${HDR_FILE} DIRECTORY)
        get_filename_component(ABSOLUTE_HDR_DIRECTORY ${HDR_DIRECTORY} ABSOLUTE)
        file(RELATIVE_PATH RELATIVE_HDR_PATH ${CMAKE_CURRENT_SOURCE_DIR} ${ABSOLUTE_HDR_DIRECTORY})
        install(FILES ${HDR_FILE} DESTINATION include/${pkgName}/${RELATIVE_HDR_PATH})
    endforeach()

    include(CMakePackageConfigHelpers)
    write_basic_package_version_file(
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}ConfigVersion.cmake"
            VERSION "${PROJECT_VERSION_STRING}"
            COMPATIBILITY AnyNewerVersion
    )

    export(EXPORT ${pkgName}Targets
            FILE "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}Targets.cmake"
            NAMESPACE ${pkgName}::
            )

    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}Config.cmake"
            @ONLY
            )

    set(ConfigPackageLocation lib/cmake/${pkgName})
    install(EXPORT ${pkgName}Targets
            FILE
            ${pkgName}Targets.cmake
            NAMESPACE
            ${pkgName}::
            DESTINATION
            ${ConfigPackageLocation}
            )
    install(
            FILES
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}Config.cmake"
            "${CMAKE_CURRENT_BINARY_DIR}/${pkgName}/${pkgName}ConfigVersion.cmake"
            DESTINATION
            ${ConfigPackageLocation}
    )
endif()

# make installation packages
include(Packing.cmake OPTIONAL)

# Setting file variables to null
set(SRCS "")
set(HDRS "")


## This section shows how to use the above compiled library to compile the source files
## set source files
#set(SRCS
#    unit-tests/manual-CancelLocationAPI.c
#    unit-tests/manual-DetermineLocationAPI.c
#    unit-tests/manual-LocationContextTransferAPI.c
#    unit-tests/manual-LocationMeasureAPI.c
#    unit-tests/manual-UPConfigureAPI.c
#    unit-tests/manual-UPSubscribeAPI.c
#    unit-tests/manual-UPUnsubscribeAPI.c
#)

##set header files
#set(HDRS
#)

## loop over all files in SRCS variable
#foreach(SOURCE_FILE ${SRCS})
#    # Get only the file name from the file as add_executable does not support executable with slash("/")
#    get_filename_component(FILE_NAME_ONLY ${SOURCE_FILE} NAME_WE)
#    # Remove .c from the file name and set it as executable name
#    string( REPLACE ".c" "" EXECUTABLE_FILE ${FILE_NAME_ONLY})
#    # Add executable for every source file in  SRCS
#    add_executable(unit-${EXECUTABLE_FILE} ${SOURCE_FILE})
#    # Link above created library to executable and dependent library curl
#    target_link_libraries(unit-${EXECUTABLE_FILE} ${CURL_LIBRARIES} ${pkgName} )
#endforeach(SOURCE_FILE ${SRCS})
