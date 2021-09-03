const mqtt = require('mqtt');
const SerialPort = require('serialport');
const Readline = require('@serialport/parser-readline');
///dev/tty.usbserial-14220
const port = new SerialPort('/dev/cu.usbmodem142201', { baudRate: 9600});
const parser = port.pipe(new Readline({ delimiter: '\n' }));
const client = mqtt.connect("mqtt://broker.hivemq.com:1883");

client.on('connect', () => {
    console.log('connected');
});

const topic = '/group10/messages';
//const msg = 'Hello MQTT world!';

// Read the port data
port.on("open", () => {
    console.log('serial port open');
});

// Got a message from the Arduino
parser.on('data', data =>{
    console.log('got word from arduino:', data);
    client.publish(topic, data, () => {
        console.log('published the message to MQTT...');
    });
});