#if defined(MKS_ROBIN_LITE)		//robin_lite主板
  #include "main_Lite.h"
#elif defined(MKS_ROBIN) 		//MKS Robin主板
  #include "main_Robin.h"
#elif defined(MKS_ROBIN_MINI)	//MKS RobinMini主板
  #include "main_RobinMini.h"
#elif defined(MKS_ROBINPRO)		//MKS RobinPro主板 (旧的F407主板)
  #include "main_RobinPro.h"
#elif defined(MKS_ROBIN2)		//MKS Robin2主板
  #include "main_Robin2.h"
#elif defined(MKS_ROBIN2MINI)	//MKS Robin2Mini主板
  #include "main_Robin2Mini.h"
#elif defined(MKS_ROBIN_NANO)	//MKS RobinNano?÷°?
  #include "main_RobinNano.h"
#endif  

