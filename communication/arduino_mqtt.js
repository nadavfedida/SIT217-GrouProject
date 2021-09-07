const mqtt = require('mqtt');
const SerialPort = require('serialport');
const Readline = require('@serialport/parser-readline');


const port = new SerialPort('/dev/cu.usbserial-14210', { baudRate: 9600
});
const parser = port.pipe(new Readline({ delimiter: '\n' }));
const client = mqtt.connect("mqtt://broker.hivemq.com:1883");
client.on('connect', () => {
    client.subscribe('/SIT217/219222529');
    console.log('mqtt connected');
}); 
const topic = '/SIT217/219222529';
//const msg = 'Hello MQTT world!';

// Read the port data
port.on("open", () => {
    console.log('serial port open')
    ;});
    
    // Got a message from the Arduino
    parser.on('data', data =>{
        console.log('got word from arduino:', data);
        client.publish(topic, data, () => {
            console.log('published the message to MQTT...');
        });
});
client.on('message', (topic, message) => {
    console.log(`Received message on ${topic}: ${message}`);
});

client.on('message', (topic, message) => {
    if (topic == '/SIT217/219222529') {
        msg = `${message}\n`;console.log(msg);
        
//now send it to the Arduino    
port.write(msg, (err) => {
    if (err) {returnconsole.log('Error on write: ', err.message);
    }console.log('message written');
    });
}
});