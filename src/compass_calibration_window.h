#include <pebble.h>

typedef struct CompassCalibrationWindow CompassCalibrationWindow;

CompassCalibrationWindow *compass_calibration_window_create();
void compass_calibration_window_destroy(CompassCalibrationWindow *window);
Window *compass_calibration_window_get_window(CompassCalibrationWindow *window);

//! Use this function to conveniently pass the current accelerometer data to the calibration window
//! @param calibration_window The calibration window
//! @param accel_data The data you retrieve from accel_service_peek() or from any callback
void compass_calibration_window_apply_accel_data(CompassCalibrationWindow *calibration_window, AccelData accel_data);

//! manually merge in new data, not needed if you use compass_calibration_window_apply_accel_data()
void compass_calibration_window_merge_value(CompassCalibrationWindow *window, int32_t angle, uint8_t intensity);

//! manually set the indicated angle, not needed if you use compass_calibration_window_apply_accel_data()
void compass_calibration_window_set_current_angle(CompassCalibrationWindow *window, int32_t angle);
