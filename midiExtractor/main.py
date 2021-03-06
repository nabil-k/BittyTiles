from mido import MidiFile


def noteToFreq(note):
    a = 440 #frequency of A (coomon value is 440Hz)
    return int((a / 32) * (2 ** ((note - 9) / 12)))


mid = MidiFile('Fairy.mid')

newTrack = []

notes = []
times = []

for i, track in enumerate(mid.tracks):
    print('Track {}: {}'.format(i, track.name))
    preTime = 0
    for msg in track:
        if(len(notes) > 444):
            break
        if(msg.type == 'note_on' and msg.channel != 0):
            msg.velocity = 0 # silences channels we dont wanna hear
            preTime += msg.time
        else:
            msg.time += preTime
            preTime  = 0
            newTrack.append(msg)
            if(msg.type == 'note_on'):
                time = msg.time
                while(time > 255):
                    notes.append(msg.note)
                    times.append(255)
                    time = time - 255

                notes.append(msg.note)
                times.append(time)                    



       

mid.tracks[0] = newTrack
#print(newTrack)
print(notes)
print(len(notes))
print()
print(times)
print(len(times))

mid.save('new_song.mid')
