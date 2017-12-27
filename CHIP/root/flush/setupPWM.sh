# Toilet Flusher - C.H.I.P. PWM DT Overlay Initializer
# (c) Charlton Trezevant 2017 - MIT License

# This script configures the CHIP to send PWM signals on the pin PWM0. By default,
# this functionality is not enabled.
# Ensure that this script is called by /etc/rc.local on boot. Otherwise, your CHIP
# will not be able to output PWM!

# Recommended reading:
#   https://bbs.nextthing.co/t/wanted-noob-guide-to-enabling-pwm0-or-anything-else/8207/2

# Export the CHIP's PWM chip, exposing it via the the sysfs api
sudo echo 0 >/sys/class/pwm/pwmchip0/export
# Give the system a second to expose the PWM chip
sleep 1
# Set the polarity of the PWM pin to normal, meaning that we send positive voltage
sudo echo normal > /sys/class/pwm/pwmchip0/pwm0/polarity
# Enable the PWM pin
sudo echo 1 >/sys/class/pwm/pwmchip0/pwm0/enable
# Set the appropriate period for the PWM signal
sudo echo 20000000 >/sys/class/pwm/pwmchip0/pwm0/period
# Setting the duty cycle to this turns the servo to the 90 degree position, which is the home position
for the flush lever. Degree values may be converted to duty cycles with the following formula:
# duty_cycle = (deg * 11 + 500) * 1000
sudo echo 700000 >/sys/class/pwm/pwmchip0/pwm0/duty_cycle
