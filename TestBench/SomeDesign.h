#pragma once

namespace  System
{
	class IController
	{
	public:
		virtual ~IController() = default;
		virtual void Print() = 0;
		virtual void Store() = 0;
	};

	class Controller : public IController
	{
	public:
		void Print() override;
		void Store() override;
	};
}
