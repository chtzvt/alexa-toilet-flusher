# Toilet Flusher - Servo Controller Script
# (c) Charlton Trezevant 2017 - MIT License

# This script is called by main.js each time a flush command is received,
# and sends the appropriate PWM signals to the servo to pull the toilet's flush
# lever.
# Servos are controlled via PWM by manipulating duty cycles, which correspond to
# degree measures. The formula for converting a degree measure to a duty cycle
# is: (deg * 11 + 500) * 1000

# Ensure that the servo is starting from the home position (90deg, lever pointing straight down)
sudo echo 700000 > /sys/class/pwm/pwmchip0/pwm0/duty_cycle
sleep 1
# Move the servo 90deg counterclockwise, pointing the lever directly right
sudo echo 1600000 > /sys/class/pwm/pwmchip0/pwm0/duty_cycle
sleep 3
# After 3 seconds, return the lever to the home position
sudo echo 700000 > /sys/class/pwm/pwmchip0/pwm0/duty_cycle
