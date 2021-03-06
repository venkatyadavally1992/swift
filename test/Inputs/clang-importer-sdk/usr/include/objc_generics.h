#import <Foundation.h>

@interface GenericClass<T> : NSObject
- (id)initWithThing:(T)thing;
- (void)dealloc;
- (__nullable T)thing;
- (int)count;
+ (__nullable T)classThing;
- (__nonnull NSArray<T> *)arrayOfThings;

- (T __nonnull)objectAtIndexedSubscript:(uint16_t)i;
- (void)setObject:(T __nonnull)object atIndexedSubscript:(uint16_t)i;

@property (nonatomic) __nullable T propertyThing;
@end

@interface GenericClass<T> (Private)
- (__nullable T)otherThing;
+ (__nullable T)otherClassThing;
@end

void takeGenericClass(__nullable GenericClass<NSString *> *thing);

@interface GenericSubclass<T> : GenericClass<T>
@end

@protocol Pettable
- (nonnull instancetype)initWithFur:(nonnull id)fur;
- (nonnull instancetype)other;
+ (nonnull instancetype)adopt;
- (void)pet;
- (void)petWith:(nonnull id <Pettable>)other;

@property (nonatomic, class) _Nonnull id<Pettable> needingMostPets;

@end

@interface Animal : NSObject
- (nonnull instancetype)initWithNoise:(nonnull id)noise;
- (nonnull instancetype)another;
+ (nonnull instancetype)create;

- (void)eat:(Animal*)prey;

@property (nonatomic, readonly) Animal *_Nonnull buddy;

@property (nonatomic, class) Animal *_Nonnull apexPredator;

- (Animal *_Nonnull)objectAtIndexedSubscript:(NSInteger)i;
- (void)setObject:(Animal *_Nonnull)x atIndexedSubscript:(NSInteger)i;

@end

@protocol Fungible
@end

@interface FungibleContainer<T: id<Fungible>> : NSObject
@end

@interface PettableContainer<T: id<Pettable>> : NSObject
@end

@interface AnimalContainer<T: Animal *> : NSObject
@end

@interface PettableAnimalContainer<T: Animal<Pettable> *> : NSObject
@end

@interface TestConstrainedTypeParam<T> : NSObject
- (void)doThing:(__nonnull T<Pettable>)thing;
@end

