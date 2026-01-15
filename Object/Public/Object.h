#ifndef OBJECT_H
#define OBJECT_H
namespace object {
class Object {
   public:
    Object() {}

    virtual void Tick() = 0;

    virtual ~Object() = default;
};
}  // namespace object
#endif