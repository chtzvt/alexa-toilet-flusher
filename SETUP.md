# Setup Tips

This project is based on Alexa (i.e. the Alexa Voice Service), the [C.H.I.P. single
board computer](https://getchip.com/) by Next Thing Co, and a collection of Node and bash scripts.


#### Getting the CHIP ready

The CHIP is an instrumental part of this project. Its job is to serve a special HTTP API which, when called by the Alexa Voice Service, controls a servo that flushes your toilet.

Before doing anything else, make sure your CHIP is up to date with the latest kernel and updates.

Next, I recommend running the [following script](https://gist.github.com/ugate/392185a959737365834f54d5bf4aae5b).
When doing so, make sure you choose to enable the
CHIP's PWM capabilities (as this will configure the device tree overlay and enable PWM support).

Install NodeJS using `apt-get install nodejs`, and verify that your Node installation is working correctly.

After that, copy the contents of the included rc.local script to your CHIP's `/etc/rc.local`.

Next, create the directory `/root/flush/` on your CHIP, and copy the scripts from `CHIP/root/flush/` (in this repo) there.

Once all the scripts have been placed, try rebooting. If all went well, you should be able to access the HTTP API on port 9009!


#### Building the Flush Lever

As a starting point, I have included photos of my servo flush lever assembly, as well as how it connects to the toilet. You will need to connect the PWM pin of the servo to pin PWM0 on the CHIP.

Note: it's unlikely that you'll be able to supply power to the servo from your CHIP! Even with small servos, spikes in current demand often cause the CHIP to reboot. I would recommend using an external power source to ensure the servo can be driven properly.

Other note: When purchasing a servo, make sure to get one that will have enough torque to activate your toilet's flush mechanism. I would also recommend taking care to [protect the servo from moisture](http://www.instructables.com/id/Water-proofing-a-Servo/), though I have no experience with long-term installations.
If you plan to leave this system in place for a long time, marine servos are probably your best bet.


#### Notes on the Alexa Skill

All the necessary parts of the Alexa skill are also included in this repository. However, I should make note of a few things:

In my configuration, I was able to have the Alexa Voice Service call my CHIP's HTTP API directly. However, AVS requires that skills configured in this way provide an HTTPS endpoint to be called.

The included Flushing API server does not support HTTPS whatsoever. So, I'll admit that my configuration was only possible due to an intermediary reverse proxy of mine which exposed the CHIP using HTTPS.

An alternative configuration to my original one, which sidesteps the HTTPS requirement, would be to point AVS at a Lambda function instead. In the code for that lambda function, you can easily fire off an HTTP call to your own Flush API.

Best of luck, and enjoy!
