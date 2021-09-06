const mqtt = require('mqtt');
const client = mqtt.connect("mqtt://broker.hivemq.com:1883");

client.on('connect', () => {
    client.subscribe('/SIT217/219222529');
    console.log('mqtt connected');
});

client.on('message', (topic, message) => {
    console.log(`Received message on ${topic}: ${message}`);
});

client.on('message', (topic, message) => {
    if (topic == '/SIT217/219222529') {    
    msg = `${message}`;
    console.log(msg)
;}
});