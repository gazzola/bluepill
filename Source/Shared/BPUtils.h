//  Copyright 2016 LinkedIn Corporation
//  Licensed under the BSD 2-Clause License (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at https://opensource.org/licenses/BSD-2-Clause
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OF ANY KIND, either express or implied.  See the License for the specific language governing permissions and limitations under the License.


#define min(a, b) ({ \
__typeof__(a) _a = (a); \
__typeof__(b) _b = (b); \
_a < _b ? _a : _b; \
})

#import <Foundation/Foundation.h>

// These must match Messages in BPUtils.m
typedef NS_ENUM(int, BPKind) {
    TIMEOUT   = 8,
    CRASH     = 7,
    FAILED    = 6,
    PASSED    = 5,
    ERROR     = 4,
    WARNING   = 3,
    INFO      = 2,
    DEBUGINFO = 1 // DEBUG collides with a #define, so DEBUGINFO it is
};

@interface BPUtils : NSObject

/*!
 @discussion set logging level
 @param level the log level
 */
+ (void)setLogLevel:(BPKind) level ;

/*!
 @discussion omit all output except fatal errors
 @param enable True enables quiet mode, False disables it.
 */
+ (void)quietMode:(BOOL)enable;

/*!
 @discussion returns true if the environment variable `BPBuildScript` is set to `YES`
 which indicates that the application is running via the build script
 */
+ (BOOL)isBuildScript;

/*!
 @discussion creates a temporary directory via mkdtemp(3)
 @param pathTemplate a path in which to create the temporary directory.
 It doesn't need to be unique since a unique identifier will be appended 
 to it.
 @param error an error if creating the temporary directory failed.
 @return the path of the temporary directory created.
 */
+ (NSString *)mkdtemp:(NSString *)pathTemplate withError:(NSError **)error;

/*!
 @discussion returns a temporary path name via mkstemp(3)
 @param pathTemplate the path of the temporary file. It doesn't need to be
 unique since a unique identifier will be appended.
 @param error an error if creating the temporary file name failed.
 @return the path of the temporary file.
 */
+ (NSString *)mkstemp:(NSString *)pathTemplate withError:(NSError **)error;


/*!
 @discussion print a message to stdout.
 @param kind one of the levels in BPKind
 @param fmt a format string (a la printf), followed by the var args.
 */
+ (void)printInfo:(BPKind)kind withString:(NSString *)fmt, ...;

/*!
 @discussion get an NSError *
 This is not really meant to be called, use the BP_ERROR macro below instead.
 @param function The name of the function
 @param line The line number
 @param fmt a format string (a la printf), followed by var args.
 */
+ (NSError *)BPError:(const char *)function andLine:(int)line withFormat:(NSString *)fmt, ... ;

#define VA_ARGS(...) , ##__VA_ARGS__
#define BP_ERROR(fmt, ...) [BPUtils BPError:__func__ andLine:__LINE__ withFormat:fmt VA_ARGS(__VA_ARGS__)]

/*!
 @discussion a function to determine if the given file name represents
 stdout. A file name is considered stdout if it is '-' or 'stdout'.
 @param fileName the file name to check.
 @return whether it's stdout.
 */
+ (BOOL)isStdOut: (NSString *)fileName;

/*!
 * @discussion return the build arguments and environment
 * @param schemePath the path to the scheme file
 * @return return the ArgsAndEnvironement as a dictionary:
 *          @{@"args":@[argument_list], @"env":@{env_dictionary}}
 */
+ (NSDictionary *)buildArgsAndEnvironmentWith:(NSString *)schemePath;

/*!
 * @discussion run a shell command and return the output
 * @param command the shell command to run
 * @return return the shell output
 */
+ (NSString *)runShell:(NSString *)command;

typedef BOOL (^BPRunBlock)(void);

/*!
 * @discussion spin block till either it returns YES or timeout.
 * @param time timeout time
 * @param block the block to run
 * @return return whether the block returns YES or not.
 */
+ (BOOL)runWithTimeOut:(NSTimeInterval)time until:(BPRunBlock)block;

@end
