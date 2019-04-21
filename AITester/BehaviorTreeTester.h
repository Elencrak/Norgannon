#include "Achitecture/BehaviorTree/Tree.h"
#include "Achitecture/BehaviorTree/Selector.h"
#include "Achitecture/BehaviorTree/Sequence.h"
#include "Achitecture/BehaviorTree/Task.h"
#include "Achitecture/BehaviorTree/Descriptor.h"
#include <iostream>

using namespace BehaviorTree;

enum Test
{
	NoneTrue = 0,
	FirstTrue = 1,
	SecondTrue = 2,
	AllTrue = 3
};

class Environment // will be remplace by a blackboard
{
public:
	Test test;
	bool runSequence;
};


void RunBehaviorTreeTests()
{
	std::shared_ptr<Environment> environment = std::make_shared<Environment>();
	environment->test = Test::NoneTrue;
	environment->runSequence = true;
	Tree bt = Tree();
	auto root = bt.GetRoot();
	// Create Sequence
	std::shared_ptr<Sequence> sequence = std::make_shared<Sequence>();
	sequence->AddDescriptor(Descriptor([environment]() {
		return environment->runSequence;
	}));
	auto sequence1 = std::make_shared<Task>([environment]() {std::cout << "Sequence 1" << std::endl; return true; });
	sequence1->AddDescriptor(Descriptor([environment]() {return Test::FirstTrue & environment->test; }));
	sequence->AddChildNode(sequence1);

	auto sequence2 = std::make_shared<Task>([environment]() {std::cout << "Sequence 2" << std::endl; return true; });
	sequence2->AddDescriptor(Descriptor([environment]() {return Test::SecondTrue & environment->test; }));

	sequence->AddChildNode(sequence2);
	// Create Selector
	std::shared_ptr<Selector> selector = std::make_shared<Selector>();
	selector->AddDescriptor(Descriptor([environment]() {
		return !environment->runSequence;
	}));
	auto selector1 = std::make_shared<Task>([environment]() {std::cout << "Selector 1" << std::endl; return true; });
	selector1->AddDescriptor(Descriptor([environment]() {return Test::FirstTrue & environment->test; }));
	selector->AddChildNode(selector1);

	auto selector2 = std::make_shared<Task>([environment]() {std::cout << "Selector 2" << std::endl; return true; });
	selector2->AddDescriptor(Descriptor([environment]() {return Test::SecondTrue & environment->test; }));
	selector->AddChildNode(selector2);

	root->AddChildNode(sequence);
	root->AddChildNode(selector);
	root->AddChildNode(std::make_shared<Task>([environment]() {std::cout << "Does nothing" << std::endl; return true; }));


	// Sequence None true
	std::cout << "Sequence None true" << std::endl;
	environment->runSequence = true;
	environment->test = Test::NoneTrue;
	bt.Run();

	// Selector None true
	std::cout << "Selector None true" << std::endl;
	environment->runSequence = false;
	bt.Run();

	// Sequence First true
	std::cout << "Sequence First true" << std::endl;
	environment->runSequence = true;
	environment->test = Test::FirstTrue;
	bt.Run();

	// Selector First true
	std::cout << "Selector First true" << std::endl;
	environment->runSequence = false;
	bt.Run();

	// Sequence Second true
	std::cout << "Sequence Second true" << std::endl;
	environment->runSequence = true;
	environment->test = Test::SecondTrue;
	bt.Run();

	// Selector Second true
	std::cout << "Selector Second true" << std::endl;
	environment->runSequence = false;
	bt.Run();

	// Sequence All true
	std::cout << "Sequence All true" << std::endl;
	environment->runSequence = true;
	environment->test = Test::AllTrue;
	bt.Run();

	// Selector First true
	std::cout << "Selector All true" << std::endl;
	environment->runSequence = false;
	bt.Run();
}
