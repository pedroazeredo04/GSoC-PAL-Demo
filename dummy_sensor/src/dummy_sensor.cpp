#include <gz/sim/System.hh>
#include <gz/plugin/Register.hh>
#include <gz/transport/Node.hh>
#include <gz/msgs.hh>
#include <gz/transport.hh>

#include <iostream>

namespace dummy_sensor
{
  class DummySensor:
    public gz::sim::System,
    public gz::sim::ISystemConfigure
  {
  public:
    DummySensor() : node()
    {
      publisher = node.Advertise<gz::msgs::StringMsg>("/dummy_sensor_topic");

      node.Subscribe("/dummy_sensor_topic",
        &DummySensor::OnMessageReceived, this);
    }

    void Configure(const gz::sim::Entity &_entity,
                   const std::shared_ptr<const sdf::Element> &_sdf,
                   gz::sim::EntityComponentManager &_ecm,
                   gz::sim::EventManager &_eventMgr) override
    {
      (void)_entity;
      (void)_sdf;
      (void)_ecm;
      (void)_eventMgr;

      gz::msgs::StringMsg msg;
      msg.set_data("Hello World from DummySensor!");
      publisher.Publish(msg);
      std::cout << "Dummy Sensor loaded and message published!\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
    }

  private:
    gz::transport::Node node;
    gz::transport::Node::Publisher publisher;

    // Callback to receive messages on the same topic
    void OnMessageReceived(const gz::msgs::StringMsg &_msg)
    {
      std::cout << "Message received: " << _msg.data() << "\n\n\n\n\n\n\n\n\n\n" << std::endl;
    }
  };
} // namespace dummy_sensor

GZ_ADD_PLUGIN(dummy_sensor::DummySensor,
              gz::sim::System,
              dummy_sensor::DummySensor::ISystemConfigure
)
