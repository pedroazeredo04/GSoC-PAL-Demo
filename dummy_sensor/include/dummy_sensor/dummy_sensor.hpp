#include <gz/sim/System.hh>
#include <gz/transport/Node.hh>

namespace dummy_sensor
{
  class DummySensor:
    public gz::sim::System,
    public gz::sim::ISystemConfigure
  {
    public: DummySensor() : node();
 
    public: ~DummySensor() override;
 
    public: void PostUpdate(const gz::sim::UpdateInfo &_info,
                const gz::sim::EntityComponentManager &_ecm) override;
  };
}