/* implements the {\tt gg::MObjectCreator} class designed in a Builder pattern
 * to provide initialization for the data contained inside gg::MObject.
 */

#ifndef OBJECTCREATOR_H
#define OBJECTCREATOR_H

#include "Object.h"
#include "MeshManipulators.h"

#include <irrlicht.h>
#include <btBulletCollisionCommon.h>
#include <btBulletDynamicsCommon.h>
#include <LinearMath/btAlignedObjectArray.h>
#include <LinearMath/btConvexHullComputer.h>
#include <LinearMath/btQuaternion.h>
#include <btHACDCompoundShape.h>

#include <string>
#include <vector>
#include <memory>

namespace gg
{

    class MObjectCreator
    {
    public:
        MObjectCreator(irr::IrrlichtDevice *);

        std::unique_ptr<MObject> createMeshRigidBody(std::vector<std::string> &&);

        std::unique_ptr<MObject> createBoxedRigidBody(std::vector<std::string> &&);

        std::unique_ptr<MObject> createSolidGround(std::vector<std::string> &&);

        std::unique_ptr<MObject> shoot(btVector3 position, btVector3 impulse);

        std::unique_ptr<MObject> createMeshRigidBodyWithTmpShape(irr::scene::IMesh *mesh, btVector3 position,
                                     btScalar mass, MObject::Type type,
                                     MeshManipulators::Nef_polyhedron &&poly);

    private:
        irr::IrrlichtDevice *m_irrDevice;
        const std::string m_media = "media/";
    };

}
#endif // OBJECTCREATOR_H
