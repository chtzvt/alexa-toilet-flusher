/*
  Toilet Flusher HTTP API
  (c) Charlton Trezevant 2017
  MIT License
  
  Some warnings:
    - This server was written in the span of an hour for a one-off project, and
    should not be considered "production-ready" out-of-the-box.
    - You should be wary of the utter lack of authentication/validation herein
    - You should also consider the security risks exposing your toilet to the internet
    (as well as the moral and philosophical implications of this)
    
  Recommended usage:
    By default, this server is started by /etc/rc.local, and run persistently (backgrounded with nohup)
    This is a bit of a kludgy way of going about it, but it worked well enough for my needs at the time.
    More persistent installations may want to use something like PM2 or an equivalent.
    
*/

var http = require('http');
var exec = require('child_process').exec;
var PORT = 9009;

http.createServer(function (req, res) {
    // Flush the toilet immediately, without validating anything at all.
    // Some sanity checks would be well leveraged here
    flushToilet();
    console.log("Flushing!");
    res.writeHead(200, { 'Content-Type': 'application/json' });
    // Respond to the HTTP request with JSON in the format that AVS expects
    res.end(JSON.stringify(getResponseJSON()));
}).listen(PORT);

// This function only calls the servoCtl script.
// Servo control is done in this way because node/johnny-five et.al weren't playing
// nice with the CHIP's DT overlay for PWM, but bash was because it's not an
// abomination of various abused web technologies.
function flushToilet(){
        exec('sudo bash /root/flush/servoCtl.sh', function(){});
}

// This function returns an opject which corresponds to the JSON structure that
// the Alexa Voice Service expects to receive.
// Done so because I just think it's a nicer way to embed and use hardcoded JSON.
function getResponseJSON(){
    return {
      "version": "1.0",
      "response": {
        "outputSpeech": {
          "type": "PlainText",
          "text": "God Bless Silicon Valley."
        },
        "card": {
          "content": "I pushed a lever for you.",
          "title": "Toilet Flusher",
          "type": "Simple"
        },
        "shouldEndSession": true
      },
      "sessionAttributes": {}
    };
}
