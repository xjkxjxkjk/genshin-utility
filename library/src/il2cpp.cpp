#include <common.hpp>

namespace GenshinUtility {
  void GIl2Cpp::Init() noexcept {
    while (!(m_unityPlayer = GetModuleHandleA("UnityPlayer.dll")))
      Sleep(100);
  
    m_setFieldOfView = reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(m_unityPlayer) + 0xbb63d0); // "Cannot set field of view on this camera while VR is enabled." -> xref calling function that uses jmp
    m_targetFrameRate = reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(m_unityPlayer) + 0x1ba1b04); // 8B 05 ? ? ? ? 66 0F 6E C8 0F 5B C9 EB -> variable referenced in mov
    m_setVsyncCount = reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(m_unityPlayer) + 0x119ca50); // 48 83 EC 28 48 63 41 -> xref calling function 
    m_setFog = reinterpret_cast<void*>(reinterpret_cast<std::uintptr_t>(m_unityPlayer) + 0x11983b0);
  }
}