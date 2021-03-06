#import <Foundation/Foundation.h>

typedef NSString *(^CALLABLE_TO_STRING)(id);
typedef NSNumber *(^CALLABLE_TO_NUMBER)(id);
typedef NSString *(^ACCUMULATOR_TO_STRING)(id, id);

static CALLABLE_TO_STRING TL_upperCase() {
    return [[^(id <NSObject> item) {
        return [item description].uppercaseString;
    } copy] autorelease];
}

static ACCUMULATOR_TO_STRING TL_appendWithSeparator(NSString *separator) {
    return [[^(id left, id right) {
        return [[[left description] stringByAppendingString:separator] stringByAppendingString:[right description]];
    } copy] autorelease];
}

static CALLABLE_TO_NUMBER TL_increment() {
    return [[^(NSNumber *item) {
        return [NSNumber numberWithLong:item.longValue + 1];
    } copy] autorelease];
}

@interface Callables : NSObject
+ (NSString * (^)(NSString *))toUpperCase;

+ (NSString * (^)(NSString *, NSString *))appendString;
@end