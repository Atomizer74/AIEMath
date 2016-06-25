#include "SceneGraph.h"
#include <algorithm>

namespace Math
{

	SceneNode::SceneNode()
	{
		m_parent = nullptr;
	}

	SceneNode::~SceneNode()
	{

	}

	void SceneNode::AddChild(SceneNode* pChild)
	{
		// Safety check
		if (pChild == nullptr)
			return;

		pChild->m_parent = this;
		this->m_children.push_back(pChild);
	}

	void SceneNode::RemoveChild(SceneNode* pChild)
	{
		// Safety check
		if (pChild == nullptr)
			return;

		this->m_children.erase(std::remove(this->m_children.begin(), this->m_children.end(), pChild), this->m_children.end());
		Cleanup(pChild);
	}

	void SceneNode::UpdateTransform()
	{
		if (m_parent != nullptr)
			m_globalTransform = m_localTransform * m_parent->m_globalTransform;
		else
			m_globalTransform = m_localTransform;

		for each (auto child in this->m_children)
		{
			child->UpdateTransform();
		}
	}

	void SceneNode::SetLocalTransform(const Matrix3& refMatrix)
	{
		m_localTransform = refMatrix;
	}

	// Recursive method to cleanup this node and all children nodes
	void SceneNode::Cleanup(SceneNode* pNode)
	{
		// Base case
		if (pNode == nullptr)
			return;

		// Cleanup children
		for each (SceneNode* child in pNode->m_children)
		{
			Cleanup(child);
		}
		pNode->m_children.clear();

		// Cleanup this node
		delete pNode;
	}




	Scene::Scene()
	{
		m_pSceneRoot = nullptr;
	}

	Scene::~Scene()
	{
		Clear();
	}

	void Scene::Clear()
	{
		SceneNode::Cleanup(m_pSceneRoot);
		m_pSceneRoot = nullptr;
	}

	void Scene::UpdateTransform()
	{
		m_pSceneRoot->UpdateTransform();
	}

	void Scene::SetRoot(SceneNode* pNode)
	{
		if (m_pSceneRoot != nullptr)
			SceneNode::Cleanup(m_pSceneRoot);

		m_pSceneRoot = pNode;
	}
}