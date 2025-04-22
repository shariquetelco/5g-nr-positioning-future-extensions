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

set(pkgName "ngmlc_location")

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
    model/accuracy_fulfilment_indicator.c
    model/alert_limit.c
    model/area_event_info.c
    model/area_event_info_addition.c
    model/area_event_info_ext.c
    model/cancel_loc_data.c
    model/civic_address.c
    model/ecgi.c
    model/ellipsoid_arc.c
    model/ellipsoid_arc_all_of.c
    model/event_notify_data.c
    model/event_notify_data_additional_info.c
    model/event_notify_data_ext.c
    model/event_notify_data_type.c
    model/external_client_type.c
    model/failure_cause.c
    model/fix_type.c
    model/gad_shape.c
    model/geographic_area.c
    model/geographical_coordinates.c
    model/gnss_id.c
    model/gnss_positioning_method_and_usage.c
    model/high_accuracy_gnss_metrics.c
    model/horizontal_velocity.c
    model/horizontal_velocity_with_uncertainty.c
    model/horizontal_with_vertical_velocity.c
    model/horizontal_with_vertical_velocity_and_uncertainty.c
    model/indoor_outdoor_ind.c
    model/input_data.c
    model/input_data_reporting_ind.c
    model/input_ranging_data.c
    model/integrity_requirements.c
    model/invalid_param.c
    model/ipv6_addr.c
    model/lcs_priority.c
    model/lcs_qos_class.c
    model/lcs_service_auth.c
    model/lcs_service_auth_any_of.c
    model/ldr_type.c
    model/loc_update_data.c
    model/loc_update_notification.c
    model/loc_update_subs.c
    model/local2d_point_uncertainty_ellipse.c
    model/local2d_point_uncertainty_ellipse_all_of.c
    model/local3d_point_uncertainty_ellipsoid.c
    model/local3d_point_uncertainty_ellipsoid_all_of.c
    model/local_area.c
    model/local_origin.c
    model/location_data.c
    model/location_data_ext.c
    model/location_privacy_ver_result.c
    model/location_privacy_ver_result_any_of.c
    model/location_qo_s.c
    model/location_request_type.c
    model/location_type_requested.c
    model/los_nlos_measure_ind.c
    model/lp_hap_type.c
    model/lp_hap_type_any_of.c
    model/mapped_location_qo_s_eps.c
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
    model/privacy_check_id_mapping_req_data.c
    model/privacy_check_id_mapping_resp_data.c
    model/problem_details.c
    model/pseudonym_indicator.c
    model/query_param_combination.c
    model/query_parameter.c
    model/range_direction.c
    model/ranging_data.c
    model/ranging_datas.c
    model/ranging_sl_result.c
    model/redirect_response.c
    model/related_ue.c
    model/related_ue_type.c
    model/relative_cartesian_location.c
    model/reporting_area.c
    model/reporting_area_type.c
    model/reporting_ind.c
    model/reporting_ind_any_of.c
    model/response_time.c
    model/snssai.c
    model/success_type.c
    model/supported_gad_shapes.c
    model/tai.c
    model/termination_cause.c
    model/ue_privacy_requirements.c
    model/uncertainty_ellipse.c
    model/uncertainty_ellipsoid.c
    model/up_cum_evt_rpt_criteria.c
    model/up_loc_rep_addr_af_rm.c
    model/up_loc_rep_info_af.c
    model/usage.c
    model/velocity_estimate.c
    model/velocity_requested.c
    model/vertical_direction.c
    api/CancelLocationAPI.c
    api/PrivacyCheckIdMappingAPI.c
    api/RequestLocationAPI.c
    api/RequestRangingAPI.c
    api/UELocationInformationSubscriptionCreationAPI.c
    api/UpdateLocationAPI.c

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
    model/accuracy_fulfilment_indicator.h
    model/alert_limit.h
    model/area_event_info.h
    model/area_event_info_addition.h
    model/area_event_info_ext.h
    model/cancel_loc_data.h
    model/civic_address.h
    model/ecgi.h
    model/ellipsoid_arc.h
    model/ellipsoid_arc_all_of.h
    model/event_notify_data.h
    model/event_notify_data_additional_info.h
    model/event_notify_data_ext.h
    model/event_notify_data_type.h
    model/external_client_type.h
    model/failure_cause.h
    model/fix_type.h
    model/gad_shape.h
    model/geographic_area.h
    model/geographical_coordinates.h
    model/gnss_id.h
    model/gnss_positioning_method_and_usage.h
    model/high_accuracy_gnss_metrics.h
    model/horizontal_velocity.h
    model/horizontal_velocity_with_uncertainty.h
    model/horizontal_with_vertical_velocity.h
    model/horizontal_with_vertical_velocity_and_uncertainty.h
    model/indoor_outdoor_ind.h
    model/input_data.h
    model/input_data_reporting_ind.h
    model/input_ranging_data.h
    model/integrity_requirements.h
    model/invalid_param.h
    model/ipv6_addr.h
    model/lcs_priority.h
    model/lcs_qos_class.h
    model/lcs_service_auth.h
    model/lcs_service_auth_any_of.h
    model/ldr_type.h
    model/loc_update_data.h
    model/loc_update_notification.h
    model/loc_update_subs.h
    model/local2d_point_uncertainty_ellipse.h
    model/local2d_point_uncertainty_ellipse_all_of.h
    model/local3d_point_uncertainty_ellipsoid.h
    model/local3d_point_uncertainty_ellipsoid_all_of.h
    model/local_area.h
    model/local_origin.h
    model/location_data.h
    model/location_data_ext.h
    model/location_privacy_ver_result.h
    model/location_privacy_ver_result_any_of.h
    model/location_qo_s.h
    model/location_request_type.h
    model/location_type_requested.h
    model/los_nlos_measure_ind.h
    model/lp_hap_type.h
    model/lp_hap_type_any_of.h
    model/mapped_location_qo_s_eps.h
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
    model/privacy_check_id_mapping_req_data.h
    model/privacy_check_id_mapping_resp_data.h
    model/problem_details.h
    model/pseudonym_indicator.h
    model/query_param_combination.h
    model/query_parameter.h
    model/range_direction.h
    model/ranging_data.h
    model/ranging_datas.h
    model/ranging_sl_result.h
    model/redirect_response.h
    model/related_ue.h
    model/related_ue_type.h
    model/relative_cartesian_location.h
    model/reporting_area.h
    model/reporting_area_type.h
    model/reporting_ind.h
    model/reporting_ind_any_of.h
    model/response_time.h
    model/snssai.h
    model/success_type.h
    model/supported_gad_shapes.h
    model/tai.h
    model/termination_cause.h
    model/ue_privacy_requirements.h
    model/uncertainty_ellipse.h
    model/uncertainty_ellipsoid.h
    model/up_cum_evt_rpt_criteria.h
    model/up_loc_rep_addr_af_rm.h
    model/up_loc_rep_info_af.h
    model/usage.h
    model/velocity_estimate.h
    model/velocity_requested.h
    model/vertical_direction.h
    api/CancelLocationAPI.h
    api/PrivacyCheckIdMappingAPI.h
    api/RequestLocationAPI.h
    api/RequestRangingAPI.h
    api/UELocationInformationSubscriptionCreationAPI.h
    api/UpdateLocationAPI.h

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
#    unit-tests/manual-PrivacyCheckIdMappingAPI.c
#    unit-tests/manual-RequestLocationAPI.c
#    unit-tests/manual-RequestRangingAPI.c
#    unit-tests/manual-UELocationInformationSubscriptionCreationAPI.c
#    unit-tests/manual-UpdateLocationAPI.c
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
