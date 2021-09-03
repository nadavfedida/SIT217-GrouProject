const mqtt = require('mqtt');
const client = mqtt.connect("mqtt://broker.hivemq.com:1883");

client.on('connect', () => {
    client.subscribe('/group10/messages');
    console.log('mqtt connected');
});

client.on('message', (topic, message) => {
    console.log(`Received message on ${topic}: ${message}`);
});

client.on('message', (topic, message) => {
    if (topic == '/group10/messages') {    
    msg = `${message}`;
    console.log(msg)
;}
});