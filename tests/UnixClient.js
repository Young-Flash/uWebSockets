var WebSocket = require('ws').WebSocket;
const client = new WebSocket('ws+unix://' + __dirname + '/ws.sock')

client.on('open', function open() {
    console.log('websocket connection established')
    client.send("{\"topic\":12}");
})

client.on('message', function message(data) {
    console.log('received: %s', data);
});

// node UnixClient.js