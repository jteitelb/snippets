// practice JS problem from pramp.com

// Add your implementation here, and initialize eventEmitter with an actual value;
const eventEmitter = {
  events: {},
  on(event, callback) {
    if (!this.events.hasOwnProperty(event)) {
      this.events[event] = [];
    }
    this.events[event].push(callback);
  },
  emit(event, msg) {
    if (this.events.hasOwnProperty(event)) {
      this.events[event].forEach((el) => el(msg));
    }
  },
  off(event, callback) {
    if (this.events.hasOwnProperty(event)) {
      callbackArr = this.events[event];
      callbackArr.splice(callbackArr.indexOf(callback), 1);
    }
  },
  once(event, callback) {
    newCallback = (msg) => {
      callback(msg);
      this.off(event, newCallback);
    };
    this.on(event, newCallback);
  },
};

function responseToEvent(msg) {
  console.log(msg);
}

eventEmitter.on("pramp", responseToEvent);
eventEmitter.once("pramp", function (msg) {
  console.log(msg + " just once!");
});
eventEmitter.emit("pramp", "1st");
eventEmitter.emit("pramp", "2nd");
eventEmitter.off("pramp", responseToEvent);
eventEmitter.emit("pramp", "3rd");
eventEmitter.emit("pramp", "1st");
