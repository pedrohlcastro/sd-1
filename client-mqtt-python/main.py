import paho.mqtt.client as mqtt
import time

def publish(agent, topic, message):
    agent.publish(topic, message)


def subscribe(agent, topic):
    agent.subscribe(topic)

def on_message(client, userdata, message):
    print("message received " ,str(message.payload.decode("utf-8")))
    print("message topic=",message.topic)
    print("message qos=",message.qos)
    print("message retain flag=",message.retain)

if __name__ == "__main__":

    URL = "192.168.0.106"

    client = mqtt.Client("pc_client")
    client.on_message = on_message

    client.connect(URL)
    client.loop_start()

    client.subscribe("a")
    client.publish("a", "My-message")    
    time.sleep(4)
    client.loop_stop()
