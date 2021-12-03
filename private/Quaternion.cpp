#include <Vector.h>
#include <Quaternion.h>

namespace Math
{
	static void QuaternionTest()
	{
		const Quaternionf identityFloat = Quaternionf::GetIdentity();
		const Quaterniond identityDouble = Quaterniond::GetIdentity();

		const Quaternionf constructorTestf = Quaternionf();
		const Quaterniond constructorTestd = Quaterniond();

		const Quaternionf axisTestf(Vector3f::UNIT_Z, 3.14159f);
		const Quaterniond axisTestd(Vector3d::UNIT_Z, 3.14159);
	}
}