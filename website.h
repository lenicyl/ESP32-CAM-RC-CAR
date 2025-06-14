#ifndef WEBSITE_H
#define WEBSITE_H

static const char PROGMEM INDEX_HTML[] = R"rawliteral(
<html>
  <head>
    <title>ESP32-CAM RC Car</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
      body { 
        font-family: Arial; 
        text-align: center; 
        margin:0px auto; 
        padding-top: 30px;
      }
      table { 
        margin-left: auto; 
        margin-right: auto; 
      }
      td { 
        padding: 8 px; 
      }
      img {
        width: auto ;
        max-width: 100% ;
        height: auto ; 
      }

      
      .button {
        background-color: #2f4468;
        border: none;
        border-radius: 5px;
        color: white;
        padding: 10px 20px;
        text-align: center;
        text-decoration: none;
        display: inline-block;
        font-size: 18px;
        margin: 6px 3px;
        cursor: pointer;
        width: 55px;
        height: 55px;
        vertical-align: middle;
        line-height: 27.5px;
        -webkit-touch-callout: none;
        -webkit-user-select: none;
        -khtml-user-select: none;
        -moz-user-select: none;
        -ms-user-select: none;
        user-select: none;
        -webkit-tap-highlight-color: rgba(0,0,0,0);
      }

      #fbvalue, #rlvalue {
        display: inline-block;
        min-width: 3ch;
        text-align: right;
      }

    </style>
  </head>
  <body>
    <h1>ESP32-CAM RC Car</h1>
    <img src="" id="photo">

    <div id="control-panel">
      <div>
        <table>
          <tr><td colspan="3" align="center"><button class="button" onmousedown="sendAction('forward');" ontouchstart="sendAction('forward');" onmouseup="sendAction('stop');" ontouchend="sendAction('stop');"> &#11205; </button></td></tr>
          <tr>
            <td align="center"><button class="button" onmousedown="sendAction('left');" ontouchstart="sendAction('left');" onmouseup="sendAction('stop');" ontouchend="sendAction('stop');"> &#11207; </button></td>
            <td align="center"><button class="button" onmousedown="sendAction('stop');" ontouchstart="sendAction('stop');"> &#10006; </button></td><td align="center"><button class="button" onmousedown="sendAction('right');" ontouchstart="sendAction('right');" onmouseup="sendAction('stop');" ontouchend="sendAction('stop');"> &#11208; </button></td>
          </tr>
          <tr><td colspan="3" align="center"><button class="button" onmousedown="sendAction('backward');" ontouchstart="sendAction('backward');" onmouseup="sendAction('stop');" ontouchend="sendAction('stop');"> &#11206; </button></td></tr>
        </table>
      </div>

      <div>
        <label for="fbspeed">F/B: </label>
        <input
        type="range"
        id="fbspeed"
        name="fbspeed"
        min="0"
        max="255"
        value="200"
        list="values" />
        <span id="fbvalue">200</span>
      </div>
      <div>
        <label for="fbspeed">R/L: </label>
        <input
        type="range"
        id="rlspeed"
        name="rlspeed"
        min="0"
        max="255"
        value="200"
        list="values" />
        <span id="rlvalue">100</span>
      </div>
    </div>
      
    <datalist id="values">
      <option value="0" label="0"></option>
      <option value="64" label="64"></option>
      <option value="128" label="128"></option>
      <option value="192" label="192"></option>
      <option value="255" label="255"></option>
    </datalist>
      
    <script>
      function sendAction(dir) {
        const fbspeed = document.querySelector("#fbspeed").value;
        const rlspeed = document.querySelector("#rlspeed").value;

        url = `/action?go=${dir}&fb=${fbspeed}&rl=${rlspeed}`;
        
        var xhr = new XMLHttpRequest();
        xhr.open("GET", url, true);
        xhr.send();
      }

      const fbvalue = document.querySelector("#fbvalue");
      const fbspeed = document.querySelector("#fbspeed");
      fbvalue.textContent = fbspeed.value;
      fbspeed.addEventListener("input", (event) => {
        fbvalue.textContent = event.target.value;
      });

      const rlvalue = document.querySelector("#rlvalue");
      const rlspeed = document.querySelector("#rlspeed");
      rlvalue.textContent = rlspeed.value;
      rlspeed.addEventListener("input", (event) => {
        rlvalue.textContent = event.target.value;
      });

      window.onload = document.getElementById("photo").src = window.location.href.slice(0, -1) + ":81/stream";
    </script>
  </body>
</html>
)rawliteral";

#endif
