#pragma once

#include <vector>
#include <Matrix3.h>

namespace Math
{
	class Scene;
	class SceneNode
	{
	public:
		SceneNode();
		virtual ~SceneNode();

		// Links the node to this one
		void AddChild(SceneNode* pChild);

		// Unlinks the node from this one, and frees up memory
		void RemoveChild(SceneNode* pChild);

		void UpdateTransform();

		void SetLocalTransform(const Matrix3& refMatrix);

	protected:
		// Recursive method to cleanup this node and all children nodes
		static void Cleanup(SceneNode* pNode);

	protected:
		std::vector<SceneNode*> m_children;
		SceneNode* m_parent;

		Math::Matrix3 m_globalTransform;
		Math::Matrix3 m_localTransform;

		friend Scene;
	};

	class Scene
	{
	public:
		Scene();
		~Scene();

		// Clears the scene, freeing up all memory
		void Clear();

		// Updates the global transforms of all the scene nodes
		void UpdateTransform();

		// Sets the root scene node
		void SetRoot(SceneNode* pNode);


	protected:
		SceneNode* m_pSceneRoot;
	};
}