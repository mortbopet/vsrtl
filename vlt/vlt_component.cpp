#include "vlt_component.h"

#include "vlt_port.h"

namespace vsrtl {
namespace vlt {
Component::Component(const std::string& displayName, SimComponent* parent) : SimComponent(displayName, parent) {}

Port& Component::createInputPort(const std::string& name, unsigned width) {
    return createPort(name, m_inputPorts, width);
}
Port& Component::createOutputPort(const std::string& name, unsigned width) {
    return createPort(name, m_outputPorts, width);
}

Port& Component::createPort(std::string name, std::set<std::unique_ptr<SimPort>, PortBaseCompT>& container,
                            unsigned width) {
    verifyIsUniquePortName(name);
    Port* port = static_cast<Port*>((*container.emplace(std::make_unique<Port>(name, width, this)).first).get());

    return *port;
}

std::string Component::addSuffix(const std::string& type) {
    return type + "_" + std::to_string(m_componentSuffixes[type]++);
}

}  // namespace vlt
}  // namespace vsrtl
